#include "CLWorkItem.hpp"
#include "CLDevice.hpp"
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

			void WorkItem::AddToQueue()
			{
				SetHasCalledExecute(true);
				Ref<ENGINE::Device> device = CORE::EngineManager::GetEngineInstance()->GetSelectedDevice();
				auto clDevice = std::static_pointer_cast<ENGINE::OPENCL::Device>(device);
				cl::CommandQueue queue = clDevice->GetClQueue();
				cl::Kernel kernel = ((OPENCL::Kernel*)GetKernel())->GetCLKernel();
				cl::NDRange global(m_OutputSize);
				queue.enqueueNDRangeKernel(kernel, cl::NullRange, global, cl::NullRange);

				if (m_OutBuffer) {
					cl::Event onCompleteEvent;
					queue.enqueueReadBuffer(m_OutBuffer->GetCLBuffer(), CL_FALSE, 0, m_OutBuffer->GetByteSize(), m_OutBuffer->GetBuffer(), NULL, &onCompleteEvent);
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