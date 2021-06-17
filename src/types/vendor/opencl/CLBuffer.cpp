#include "CLBuffer.hpp"

namespace MATD {
	namespace DTYPES {
		namespace OPENCL {
			template<typename T>
			Buffer<T>::Buffer(T* buffer, size_t size): MATD::Buffer(id, buffer, size) {
				MATD_CORE_TRACE("CL_BUFFER:::Created CL Buffer id:{}", id);
			}

			template<typename T>
			void Buffer<T>::Bind(const WorkItem* workItem, size_t index)
			{
			}

			template<typename T>
			void Buffer<T>::Delete()
			{
			}
		}
	}
}