#pragma once
#include "../../matd/Image.hpp"

namespace MATD {
	namespace DTYPES {
		namespace OPENCL {
			class Image : public MATD::Image {
			public:
				Image(void* buffer, size_t size, size_t elem_size, size_t width, size_t height, buf_type argType);

				virtual void Bind(WorkItem* workItem, size_t index) override;
				virtual void Delete() override;
			};
		}
	}
}