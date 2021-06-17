#include "CLBuffer.hpp"

namespace MATD {
	namespace DTYPES {
		namespace OPENCL {
			Buffer::Buffer(void* buffer, size_t size, size_t elem_size): MATD::Buffer(buffer, size, elem_size) {
				MATD_CORE_TRACE("CL_BUFFER:::Created CL Buffer of elements:{}", size);
			}

			void Buffer::Bind(const WorkItem* workItem, size_t index)
			{
			}

			void Buffer::Delete()
			{
			}
		}
	}
}