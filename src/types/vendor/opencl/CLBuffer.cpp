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
			struct UserD {
				WorkItem* wi;
				size_t index;
			};

			Buffer::Buffer(void* buffer, size_t size, size_t elem_size, buf_type argType): MATD::Buffer(buffer, size, elem_size, argType) {
				Ref<ENGINE::Device> device = CORE::EngineManager::GetEngineInstance()->GetSelectedDevice();
				auto clDevice = std::static_pointer_cast<ENGINE::OPENCL::Device>(device);
				cl::Context clContext = clDevice->GetContext()->GetCLContext();
				auto byteSize = GetByteSize();
				m_CLBuffer = cl::Buffer(clContext, argType, byteSize);
				MATD_CORE_TRACE("CL_BUFFER:::Created CL Buffer of bytes:{} elements: {}", byteSize, size);
			}

			void Buffer::Bind(WorkItem* workItem, size_t index)
			{
				
			}

			void Buffer::Delete()
			{
			}

			void Buffer::AddToQueue(MATD::Queue* queue)
			{
			}
		}
	}
}