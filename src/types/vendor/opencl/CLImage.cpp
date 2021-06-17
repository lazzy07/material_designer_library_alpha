#include "CLImage.hpp"

namespace MATD {
	namespace DTYPES {
		namespace OPENCL {
			template<typename T>
			Image<T>::Image(T* buffer, size_t size, size_t width, size_t height): MATD::Image(id, buffer, size, width, height) {
				MATD_CORE_TRACE("CL_IMAGE:::Created CL Image id: {}", id);
			}

			template<typename T>
			void Image<T>::Bind(const WorkItem* workItem, size_t index)
			{
			}

			template<typename T>
			void Image<T>::Delete()
			{
			}
		}
	}
}