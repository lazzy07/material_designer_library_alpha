#include "CLWorkItem.hpp"
#include "CLDevice.hpp"
#include "CLQueue.hpp"
#include "../../../core/EngineManager.hpp"
#include "../../../core/MaterialDesigner.hpp"
#include "../../../core/Core.hpp"
#include "../../../graphs/shader_graph/ShaderOutputSocket.hpp"
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
				const auto argument = GetOutput();

				if (argument == nullptr) {
					MATD_CORE_WARN("MATD::OPENCL No outputs are set. Quitting compilation process");
					return;
				}

				const Ref<ENGINE::Device> device = CORE::EngineManager::GetEngineInstance()->GetSelectedDevice();
				auto clDevice = std::static_pointer_cast<ENGINE::OPENCL::Device>(device);
				const cl::CommandQueue clQueue = ((ENGINE::OPENCL::Queue*)queue)->GetCLQueue();
				auto arguments = GetArguments();

				for (auto& argument : arguments)
				{
					MATD::DTYPES::Argument*  arg = argument.second;

					arg->AddToQueue(queue);
					arg->Bind(this, argument.first);
				}

				const cl::Kernel kernel = ((OPENCL::Kernel*)GetKernel())->GetCLKernel();
				OPENCL::Queue* matClQueue = (OPENCL::Queue*)queue;

				

				cl::Event event;
				cl::Event onCompleteEvent;
				const auto events = matClQueue->GetCLEvents();

				if(argument->GetArgType() == MAT_ARG::MAT_BUFFER)
				{
					size_t size = 0;
					const auto* buffer = (MATD::DTYPES::OPENCL::Buffer*)argument;
					size = buffer->GetSize();

					cl_int err = clQueue.enqueueNDRangeKernel(kernel, cl::NullRange, size, cl::NullRange, &events, &event);
					if(err != 0) MATD_CORE_ERROR("MATD::OPENCL::WorkItem Error {}", err);
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
					region[1] = texture->GetHeight();
					region[2] = 1;

					
					cl_int err = clQueue.enqueueNDRangeKernel(kernel, cl::NullRange, cl::NDRange(texture->GetWidth(), texture->GetHeight()), cl::NullRange, &(events), &event);
					matClQueue->SetEvent(event);

					clQueue.enqueueReadImage(texture->GetCLImage(), CL_FALSE, origin, region, 0, 0,
						texture->GetBuffer(), &(matClQueue->GetCLEvents()), &onCompleteEvent);

					if (err != 0) MATD_CORE_ERROR("MATD::OPENCL::WorkItem Error {}", err);

				}else if(argument->GetArgType() == MAT_ARG::MAT_TEXCOLOR)
				{
					const auto* texture = (MATD::DTYPES::OPENCL::ColorTexture*)argument;

					cl::size_t<3> origin;
					cl::size_t<3> region;
					origin[0] = 0;
					origin[1] = 0;
					origin[2] = 0;

					region[0] = texture->GetWidth();
					region[1] = texture->GetHeight();
					region[2] = 1;

					cl_int err = clQueue.enqueueNDRangeKernel(kernel, cl::NullRange, cl::NDRange(texture->GetWidth(), texture->GetHeight()), cl::NullRange, &(events), &event);
					matClQueue->SetEvent(event);

					clQueue.enqueueReadImage(texture->GetCLImage(), CL_FALSE, origin, region, 0, 0,
						texture->GetBuffer(), &(matClQueue->GetCLEvents()), &onCompleteEvent);

					if (err != 0) MATD_CORE_ERROR("MATD::OPENCL::WorkItem Error {}", err);
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
				if(const auto node = GetNode())
				{
					const auto socket = dynamic_cast<GRAPH::ShaderOutputSocket*>(node->GetOutputSocket("out").get());
					socket->Update();

					const auto id = node->GetID();
					MATD::CORE::MaterialDesigner::CallShaderNodeChangeCallback(id, socket->GetTexArgument().get());
				}
			}

			void WorkItem::SetOutput(size_t index, DTYPES::Argument* argument)
			{
				cl::Kernel kernel = ((OPENCL::Kernel*)GetKernel())->GetCLKernel();
				SetOutputItem(argument);
				if(argument->GetArgType() == MAT_ARG::MAT_BUFFER)
				{
					const auto* buffer = (MATD::DTYPES::OPENCL::Buffer*)argument;
					const cl::Buffer clBuffer = buffer->GetCLBuffer();
					kernel.setArg(index, clBuffer);
				}
				else if(argument->GetArgType() == MAT_ARG::MAT_TEXGRAYSCALE)
				{
					const auto* texture = (MATD::DTYPES::OPENCL::GrayscaleTexture*)argument;
					const cl::Image2D clImage = texture->GetCLImage();
					kernel.setArg(index, clImage);
				} else if(argument->GetArgType() == MAT_ARG::MAT_TEXCOLOR)
				{
					const auto* texture = (MATD::DTYPES::OPENCL::ColorTexture*)argument;
					cl::Image2D clImage = texture->GetCLImage();
					kernel.setArg(index, clImage);
				}
			}
		}
	}
}
