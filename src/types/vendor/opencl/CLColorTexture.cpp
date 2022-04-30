#include "CLColorTexture.hpp"
#include "CLTexture.hpp"
#include "../../../core/Log.hpp"
#include "../../../core/EngineManager.hpp"
#include "../../../engine/vendor/opencl/CLWorkItem.hpp"
#include "../../../engine/vendor/opencl/CLContext.hpp"
#include "../../../engine/vendor/opencl/CLDevice.hpp"
#include "../../../engine/vendor/opencl/CLQueue.hpp"

MATD::DTYPES::OPENCL::ColorTexture::ColorTexture(MATD_TEXTURE_BIT_TYPE bitType, const size_t width,
	const size_t height, const int argType) : MATD::ColorTexture(bitType, width, height, argType)
{
	MATD_CORE_TRACE("CL_COLORTEX:::Created CL Color Texture of elements: {}", this->GetSize());
	const Ref<ENGINE::Device> device = CORE::EngineManager::GetEngineInstance()->GetSelectedDevice();
	const auto clDevice = std::static_pointer_cast<ENGINE::OPENCL::Device>(device);
	const cl::Context clContext = clDevice->GetContext()->GetCLContext();
	
	const auto noOfChannels = this->GetNoOfChannels();

	const cl::ImageFormat format(OPENCL::Texture::NoOfChannelsToCLChannelTypes(noOfChannels), OPENCL::Texture::BitTypeToCLBitType(bitType));
	m_CLImage2D = cl::Image2D(clContext, argType | CL_MEM_COPY_HOST_PTR, format, width, height, 0, this->GetBuffer());
}

void MATD::DTYPES::OPENCL::ColorTexture::Bind(WorkItem* workItem, size_t index)
{
	const MATD::ENGINE::OPENCL::Kernel* kernel = (ENGINE::OPENCL::Kernel*)workItem->GetKernel();
	cl::Kernel clKernel = kernel->GetCLKernel();
	clKernel.setArg<cl::Image2D>(index, m_CLImage2D);
	MATD_CORE_TRACE("CL_ColorTEX::ColorTex bound to kernel:{} at index:{} of size: {}", kernel->GetID(), index, GetSize());
}

void MATD::DTYPES::OPENCL::ColorTexture::Delete()
{

}

void MATD::DTYPES::OPENCL::ColorTexture::AddToQueue(MATD::Queue* queue)
{
	MATD::ENGINE::OPENCL::Queue* clQueue = (MATD::ENGINE::OPENCL::Queue*)queue;
	cl::CommandQueue clCommandQueue = clQueue->GetCLQueue();
	std::vector<cl::Event> events = clQueue->GetCLEvents();
	cl::Event event;

	
	cl::size_t<3> origin;
	cl::size_t<3> region;
	origin[0] = 0;
	origin[1] = 0;
	origin[2] = 0;

	region[0] = this->GetWidth();
	region[1] = this->GetHeight();
	region[2] = 1;

	clCommandQueue.enqueueWriteImage(GetCLImage(), CL_FALSE, origin, region, 0, 0, this->GetBuffer(), &events, &event);
	clQueue->SetEvent(event);
}

