#include "CLBuffer.hpp"

namespace MATD {
	namespace DTYPES {
		namespace OPENCL {
			template<typename T>
			Buffer<T>::Buffer(size_t id, T* buffer, size_t size): MATD::Buffer(id, buffer, size) {
				MATD_CORE_TRACE("CL_BUFFER:::Created CL Buffer id:{}", id);
			}

			template<typename T>
			void Buffer<T>::Bind(const WorkItem* workItem)
			{
			}

			template<typename T>
			void Buffer<T>::Delete()
			{
			}
		}
	}
}