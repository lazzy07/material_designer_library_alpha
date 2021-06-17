#include "CLImage.hpp"

namespace MATD {
	namespace DTYPES {
		namespace OPENCL {
			Image::Image(void* buffer, size_t size, size_t elem_size, size_t width, size_t height): MATD::Image(buffer, size, elem_size, width, height) {
				MATD_CORE_TRACE("CL_IMAGE:::Created CL Image of elements: {}", size);
			}

			void Image::Bind(const WorkItem* workItem, size_t index)
			{
			}

			void Image::Delete()
			{
			}
		}
	}
}