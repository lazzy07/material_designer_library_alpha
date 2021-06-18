#include "CLBuffer.hpp"
#include "../../../core/Log.hpp"
#include "../../../engine/matd/Kernel.hpp"
#include "../../../core/EngineManager.hpp"
#include "../../../engine/vendor/opencl/CLWorkItem.hpp"
#include "../../../engine/vendor/opencl/CLContext.hpp"
#include "../../../engine/vendor/opencl/CLDevice.hpp"

namespace MATD {
	namespace DTYPES {
		namespace OPENCL {
			Buffer::Buffer(void* buffer, size_t size, size_t elem_size, buf_type argType): MATD::Buffer(buffer, size, elem_size, argType) {
				Ref<ENGINE::Device> device = CORE::EngineManager::GetEngineInstance()->GetSelectedDevice();
				auto clDevice = std::static_pointer_cast<ENGINE::OPENCL::Device>(device);
				cl::Context clContext = clDevice->GetContext()->GetCLContext();
				m_CLBuffer = cl::Buffer(clContext, argType, GetByteSize(), GetBuffer());
				MATD_CORE_TRACE("CL_BUFFER:::Created CL Buffer of elements:{}", size);
			}

			void Buffer::Bind(const WorkItem* workItem, size_t index)
			{
				const MATD::ENGINE::OPENCL::Kernel* kernel = (ENGINE::OPENCL::Kernel*)workItem->GetKernel();
				cl::Kernel clKernel = kernel->GetCLKernel();
				clKernel.setArg<cl::Buffer>(index, m_CLBuffer);
				MATD_CORE_TRACE("CL_BUFFER::Buffer bound to kernel:{} at index:{} of size: {}", kernel->GetID(), index, GetSize());
			}

			void Buffer::Delete()
			{
			}
		}
	}
}