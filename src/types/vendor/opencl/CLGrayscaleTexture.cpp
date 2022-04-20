#include "CLGrayscaleTexture.hpp"
#include "CLTexture.hpp"
#include "../../../core/Log.hpp"
#include "../../../core/EngineManager.hpp"
#include "../../../engine/vendor/opencl/CLWorkItem.hpp"
#include "../../../engine/vendor/opencl/CLContext.hpp"
#include "../../../engine/vendor/opencl/CLDevice.hpp"
#include "../../../engine/vendor/opencl/CLQueue.hpp"

MATD::DTYPES::OPENCL::GrayscaleTexture::GrayscaleTexture(MATD_TEXTURE_BIT_TYPE bitType, const size_t width,
	const size_t height, const int argType) : MATD::GrayscaleTexture(bitType, width, height, argType)
{
	MATD_CORE_TRACE("CL_GRAYSCALETEX:::Created CL Grayscale Texture of elements: {}", this->GetSize());
	const Ref<ENGINE::Device> device = CORE::EngineManager::GetEngineInstance()->GetSelectedDevice();
	const auto clDevice = std::static_pointer_cast<ENGINE::OPENCL::Device>(device);
	const cl::Context clContext = clDevice->GetContext()->GetCLContext();
	
	const auto noOfChannels = this->GetNoOfChannels();

	const cl::ImageFormat format(OPENCL::Texture::NoOfChannelsToCLChannelTypes(noOfChannels), OPENCL::Texture::BitTypeToCLBitType(bitType));
	m_CLImage2D = cl::Image2D(clContext, argType | CL_MEM_COPY_HOST_PTR, format, width, height, 0, this->GetBuffer());
}

void MATD::DTYPES::OPENCL::GrayscaleTexture::Bind(WorkItem* workItem, size_t index)
{
	const MATD::ENGINE::OPENCL::Kernel* kernel = (ENGINE::OPENCL::Kernel*)workItem->GetKernel();
	cl::Kernel clKernel = kernel->GetCLKernel();
	clKernel.setArg<cl::Image2D>(index, m_CLImage2D);
	MATD_CORE_TRACE("CL_GRAYSCALETEX::GrayscaleTex bound to kernel:{} at index:{} of size: {}", kernel->GetID(), index, GetSize());
}

void MATD::DTYPES::OPENCL::GrayscaleTexture::Delete()
{

}

void MATD::DTYPES::OPENCL::GrayscaleTexture::AddToQueue(MATD::Queue* queue)
{

}

