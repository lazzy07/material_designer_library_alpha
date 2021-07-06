#include "CLWorkItem.hpp"
#include "CLDevice.hpp"
#include "CLQueue.hpp"
#include "../../../core/EngineManager.hpp"
#include "../../../core/Core.hpp"

namespace MATD {
	namespace ENGINE {
		namespace OPENCL {
			WorkItem::WorkItem(Kernel* kernel): MATD::WorkItem(kernel) {
				m_OutBuffer = nullptr; 
				m_OutImage = nullptr;
				MATD_CORE_TRACE("CL_WORKITEM::Work Item created with OpenCL");
			}

			void WorkItem::AddToQueue(MATD::Queue* queue)
			{
				Ref<ENGINE::Device> device = CORE::EngineManager::GetEngineInstance()->GetSelectedDevice();
				auto clDevice = std::static_pointer_cast<ENGINE::OPENCL::Device>(device);

				cl::CommandQueue clQueue = ((ENGINE::OPENCL::Queue*)queue)->GetCLQueue();

				auto arguments = GetArguments();
				for (std::map<size_t, MATD::DTYPES::Argument*>::iterator it = arguments.begin(); it != arguments.end(); ++it) {
					MATD::DTYPES::Argument*  arg = it->second;

					if (arg->IsBound()) {
						MATD_CORE_TRACE("MATD_WORKITEM::Argument at index {} is already found on device and skipping", it->first);
					}
					else {
						arg->AddToQueue(queue);
					}

				}

				cl::Kernel kernel = ((OPENCL::Kernel*)GetKernel())->GetCLKernel();
				cl::NDRange global(m_OutputSize);
				clQueue.enqueueNDRangeKernel(kernel, cl::NullRange, global, cl::NullRange);

				if (m_OutBuffer) {
					cl::Event onCompleteEvent;
					clQueue.enqueueReadBuffer(m_OutBuffer->GetCLBuffer(), CL_FALSE, 0, m_OutBuffer->GetByteSize(), m_OutBuffer->GetBuffer(), NULL, &onCompleteEvent);
					onCompleteEvent.setCallback(CL_COMPLETE, [](cl_event, cl_int, void* userData) {
						WorkItem* w = (WorkItem*)userData;
						w->OnComplete();
						}, this);
				} else if(m_OutImage) {

				}
				else {
					MATD_CORE_ASSERT(false, "Output buffer/image not set");
				}
			}

			void WorkItem::OnComplete()
			{
				MATD_CORE_INFO("CL_WORKITEM:::Finished processing");
			}

			void WorkItem::SetOutput(Buffer* buffer)
			{
				m_OutputSize = buffer->GetSize();
				m_OutBuffer = (MATD::DTYPES::OPENCL::Buffer*)buffer;
				cl::Buffer clBuffer = m_OutBuffer->GetCLBuffer();
				auto args = GetArguments();
				size_t index = args.size();
				cl::Kernel kernel = ((OPENCL::Kernel*)GetKernel())->GetCLKernel();
				kernel.setArg(index, clBuffer);
			}

			void WorkItem::SetOutput(Image* image)
			{
				m_OutputSize = image->GetSize();
			}
		}
	}
}