#include "CLImage.hpp"
#include "../../../core/Log.hpp"
#include "../../../engine/matd/Kernel.hpp"
#include "../../../core/EngineManager.hpp"
#include "../../../engine/vendor/opencl/CLWorkItem.hpp"
#include "../../../engine/vendor/opencl/CLContext.hpp"
#include "../../../engine/vendor/opencl/CLDevice.hpp"
#include "../../../engine/vendor/opencl/CLQueue.hpp"

namespace MATD {
	namespace DTYPES {
		namespace OPENCL {
			int Image::NoOfChannelsToCLChannelTypes(size_t noOfChannels)
			{
				switch (noOfChannels)
				{
				case 1:
					return CL_R;
				case 3:
					return CL_RGB;
				default:
					return CL_R;
				}
			}


			int Image::BitTypeToCLBitType(MATD::MATD_TEXTURE_BIT_TYPE bitType)
			{
				switch (bitType)
				{
				case MATD::MATD_TEXTURE_BIT_TYPE::TEX_8BIT:
					return CL_UNSIGNED_INT8;
				case MATD::MATD_TEXTURE_BIT_TYPE::TEX_16BIT:
					return CL_UNSIGNED_INT16;
				case MATD::MATD_TEXTURE_BIT_TYPE::TEX_32BIT:
					return CL_UNSIGNED_INT32;
				default:
					return CL_UNSIGNED_INT8;
				};
			}


			Image::Image(void* buffer, size_t size, size_t elem_size, size_t width, size_t height, buf_type argType): MATD::Image(buffer, size, elem_size, width, height, argType) {
				MATD_CORE_TRACE("CL_IMAGE:::Created CL Image of elements: {}", size);
				Ref<ENGINE::Device> device = CORE::EngineManager::GetEngineInstance()->GetSelectedDevice();
				auto clDevice = std::static_pointer_cast<ENGINE::OPENCL::Device>(device);
				cl::Context clContext = clDevice->GetContext()->GetCLContext();

				auto texture = this->GetTexture();
				auto bitType = MATD::MATD_TEXTURE_BIT_TYPE::TEX_8BIT;
				size_t noOfChannels = 1;

				if (texture) {
					bitType = texture->GetBitType();
					noOfChannels = texture->GetNoOfChannels();
				}

				const cl::ImageFormat format(Image::NoOfChannelsToCLChannelTypes(noOfChannels), Image::BitTypeToCLBitType(bitType));
				m_CLImage2D = cl::Image2D(clContext, argType | CL_MEM_COPY_HOST_PTR, format, width, height, 0, this->GetImageData());
			}

			void Image::Bind(WorkItem* workItem, size_t index)
			{
				const MATD::ENGINE::OPENCL::Kernel* kernel = (ENGINE::OPENCL::Kernel*)workItem->GetKernel();
				cl::Kernel clKernel = kernel->GetCLKernel();
				clKernel.setArg<cl::Image2D>(index, m_CLImage2D);
				MATD_CORE_TRACE("CL_BUFFER::Buffer bound to kernel:{} at index:{} of size: {}", kernel->GetID(), index, GetSize());
			}

			void Image::Delete()
			{
			}

			void Image::AddToQueue(MATD::Queue* queue)
			{
			}
		}
	}
}