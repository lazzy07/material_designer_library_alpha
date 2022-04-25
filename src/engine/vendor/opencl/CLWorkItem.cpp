#include "CLWorkItem.hpp"
#include "CLDevice.hpp"
#include "CLQueue.hpp"
#include "../../../core/EngineManager.hpp"
#include "../../../core/Core.hpp"
#include "../../../types/matd/Texture.hpp"
#include "../../../types/vendor/opencl/CLGrayscaleTexture.hpp"
#include "../../../types/vendor/opencl/CLColorTexture.hpp"

namespace MATD {
	namespace ENGINE {
		namespace OPENCL {
			WorkItem::WorkItem(Kernel* kernel): MATD::WorkItem(kernel)
			{
				MATD_CORE_TRACE("CL_WORKITEM::Work Item created with OpenCL");
			}

			void WorkItem::AddToQueue(MATD::Queue* queue)
			{
				const Ref<ENGINE::Device> device = CORE::EngineManager::GetEngineInstance()->GetSelectedDevice();
				auto clDevice = std::static_pointer_cast<ENGINE::OPENCL::Device>(device);
				const cl::CommandQueue clQueue = ((ENGINE::OPENCL::Queue*)queue)->GetCLQueue();
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
				OPENCL::Queue* matClQueue = (OPENCL::Queue*)queue;

				auto argument = GetOutput();

				if (argument == nullptr) {
					MATD_CORE_WARN("MATD::OPENCL No outputs are set. Quitting compilation process");
					return;
				}

				cl::Event event;
				cl::Event onCompleteEvent;
				const auto events = matClQueue->GetCLEvents();
				size_t size = 0;

				if(argument->GetArgType() == MAT_ARG::MAT_BUFFER)
				{
					const auto* buffer = (MATD::DTYPES::OPENCL::Buffer*)argument;
					size = buffer->GetSize();
					clQueue.enqueueNDRangeKernel(kernel, cl::NullRange, size, cl::NullRange, &events, &event);
					matClQueue->SetEvent(event);

					clQueue.enqueueReadBuffer(buffer->GetCLBuffer(), CL_FALSE, 0, buffer->GetByteSize(), buffer->GetBuffer(), &(matClQueue->GetCLEvents()), &onCompleteEvent);
				}else if(argument->GetArgType() == MAT_ARG::MAT_TEXGRAYSCALE)
				{
					const auto* texture = (MATD::DTYPES::OPENCL::GrayscaleTexture*)argument;

					cl::size_t<3> origin;
					cl::size_t<3> region;
					origin[0] = 0;
					origin[1] = 0;
					origin[2] = 0;

					region[0] = texture->GetWidth();
					region[1] = texture->GetWidth();
					region[2] = 1;

					size = texture->GetSize();
					clQueue.enqueueNDRangeKernel(kernel, cl::NullRange, size, cl::NullRange, &events, &event);
					matClQueue->SetEvent(event);

					clQueue.enqueueReadImage(texture->GetCLImage(), CL_FALSE, origin, region, 0, 0,
						texture->GetBuffer(), &(matClQueue->GetCLEvents()), &onCompleteEvent);
				}else if(argument->GetArgType() == MAT_ARG::MAT_TEXCOLOR)
				{
					const auto* texture = (MATD::DTYPES::OPENCL::ColorTexture*)argument;

					cl::size_t<3> origin;
					cl::size_t<3> region;
					origin[0] = 0;
					origin[1] = 0;
					origin[2] = 0;

					region[0] = texture->GetWidth();
					region[1] = texture->GetWidth();
					region[2] = 1;
					size = texture->GetSize();

					clQueue.enqueueNDRangeKernel(kernel, cl::NullRange, size, cl::NullRange, &events, &event);
					matClQueue->SetEvent(event);

					clQueue.enqueueReadImage(texture->GetCLImage(), CL_FALSE, origin, region, 0, 0,
						texture->GetBuffer(), &(matClQueue->GetCLEvents()), &onCompleteEvent);
				}
				else {
					MATD_CORE_ASSERT(false, "Output buffer/image not set");
				}

				matClQueue->SetEvent(onCompleteEvent);

				onCompleteEvent.setCallback(CL_COMPLETE, [](cl_event, cl_int, void* userData) {
					auto* w = (WorkItem*)userData;
					w->OnComplete();
				}, this);
			}

			void WorkItem::OnComplete()
			{
				MATD_CORE_INFO("CL_WORKITEM:::Finished processing");
			}

			void WorkItem::SetOutput(size_t index, DTYPES::Argument* argument)
			{
				cl::Kernel kernel = ((OPENCL::Kernel*)GetKernel())->GetCLKernel();
				SetOutputItem(argument);
				if(argument->GetArgType() == MAT_ARG::MAT_BUFFER)
				{
					const auto* buffer = (MATD::DTYPES::OPENCL::Buffer*)argument;
					cl::Buffer clBuffer = buffer->GetCLBuffer();
					kernel.setArg(index, clBuffer);
				}
				else if(argument->GetArgType() == MAT_ARG::MAT_TEXGRAYSCALE)
				{
					auto* texture = (MATD::DTYPES::OPENCL::GrayscaleTexture*)argument;
					cl::Image2D clImage = texture->GetCLImage();
					kernel.setArg(index, clImage);
				} else if(argument->GetArgType() == MAT_ARG::MAT_TEXCOLOR)
				{
					auto* texture = (MATD::DTYPES::OPENCL::ColorTexture*)argument;
					cl::Image2D clImage = texture->GetCLImage();
					kernel.setArg(index, clImage);
				}
			}
		}
	}
}
