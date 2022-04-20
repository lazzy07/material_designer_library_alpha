#include "CLWorkItem.hpp"
#include "CLDevice.hpp"
#include "CLQueue.hpp"
#include "../../../core/EngineManager.hpp"
#include "../../../core/Core.hpp"

namespace MATD {
	namespace ENGINE {
		namespace OPENCL {
			WorkItem::WorkItem(Kernel* kernel): MATD::WorkItem(kernel), m_OutBuffer(nullptr), m_OutColorTexture(nullptr), m_OutGrayscaleTexture(nullptr)
			{
				MATD_CORE_TRACE("CL_WORKITEM::Work Item created with OpenCL");
			}

			void WorkItem::AddToQueue(MATD::Queue* queue)
			{
				Ref<ENGINE::Device> device = CORE::EngineManager::GetEngineInstance()->GetSelectedDevice();
				auto clDevice = std::static_pointer_cast<ENGINE::OPENCL::Device>(device);
				cl::CommandQueue clQueue = ((ENGINE::OPENCL::Queue*)queue)->GetCLQueue();
				auto arguments = GetArguments();

				for (auto it = arguments.begin(); it != arguments.end(); ++it) {
					MATD::DTYPES::Argument*  arg = it->second;
					if (arg->IsBound()) {
						MATD_CORE_TRACE("MATD_WORKITEM::Argument at index {} is already found on device", it->first);
					} else {
						arg->AddToQueue(queue);
					}
					arg->Bind(this, it->first);
					arg->SeIsBound(true);
				}

				const cl::Kernel kernel = ((OPENCL::Kernel*)GetKernel())->GetCLKernel();
				const cl::NDRange global(m_OutputSize);

				OPENCL::Queue* matClQueue = (OPENCL::Queue*)queue;
				cl::Event event;
				
				auto events = matClQueue->GetCLEvents();
				clQueue.enqueueNDRangeKernel(kernel, cl::NullRange, global, cl::NullRange, &events, &event);
				matClQueue->SetEvent(event);

				cl::Event onCompleteEvent;

				if (m_OutBuffer) {
					clQueue.enqueueReadBuffer(m_OutBuffer->GetCLBuffer(), CL_FALSE, 0, m_OutBuffer->GetByteSize(), m_OutBuffer->GetBuffer(), &(matClQueue->GetCLEvents()), &onCompleteEvent);
					matClQueue->SetEvent(onCompleteEvent);
				} else if(m_OutColorTexture) {
					//TODO:: Add image functionality
				}
				else if (m_OutGrayscaleTexture)
				{

				} else {
					MATD_CORE_ASSERT(false, "Output buffer/image not set");
				}

				onCompleteEvent.setCallback(CL_COMPLETE, [](cl_event, cl_int, void* userData) {
					WorkItem* w = (WorkItem*)userData;
					w->OnComplete();
				}, this);
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

			void WorkItem::SetOutput(ColorTexture* texture)
			{
				m_OutputSize = texture->GetSize();
				m_OutColorTexture = (MATD::DTYPES::OPENCL::ColorTexture*)texture;
				cl::Image2D clImage= m_OutColorTexture->GetCLImage();
				auto args = GetArguments();
				size_t index = args.size();
				cl::Kernel kernel = ((OPENCL::Kernel*)GetKernel())->GetCLKernel();
				kernel.setArg(index, clImage);
			}

			void WorkItem::SetOutput(GrayscaleTexture* texture)
			{
				m_OutputSize = texture->GetSize();
				m_OutGrayscaleTexture = (MATD::DTYPES::OPENCL::GrayscaleTexture*)texture;
				cl::Image2D clImage = m_OutGrayscaleTexture->GetCLImage();
				auto args = GetArguments();
				size_t index = args.size();
				cl::Kernel kernel = ((OPENCL::Kernel*)GetKernel())->GetCLKernel();
				kernel.setArg(index, clImage);
			}
		}
	}
}