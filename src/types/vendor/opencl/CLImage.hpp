#pragma once
#include "../../matd/Image.hpp"

namespace MATD {
	namespace DTYPES {
		namespace OPENCL {
			template<typename T>
			class Image : public MATD::Image<T> {
			public:
				Image(size_t id, T* buffer, size_t size, size_t width, size_t height);

				virtual void Bind(const WorkItem* workItem, size_t index) override;
				virtual void Delete() override;
			};
		}
	}
}