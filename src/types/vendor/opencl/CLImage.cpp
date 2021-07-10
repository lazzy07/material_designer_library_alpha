#include "CLImage.hpp"

namespace MATD {
	namespace DTYPES {
		namespace OPENCL {
			Image::Image(void* buffer, size_t size, size_t elem_size, size_t width, size_t height, buf_type argType): MATD::Image(buffer, size, elem_size, width, height, argType) {
				MATD_CORE_TRACE("CL_IMAGE:::Created CL Image of elements: {}", size);
			}

			void Image::Bind(WorkItem* workItem, size_t index)
			{
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