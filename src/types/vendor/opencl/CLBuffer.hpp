#pragma once
#include "../../matd/Buffer.hpp"

namespace MATD {
	namespace DTYPES {
		namespace OPENCL {
			template <typename T>
			class Buffer : public MATD::Buffer<T> {
			public:
				Buffer(size_t id, T* buffer, size_t size);

				virtual void Bind(const WorkItem* workItem, size_t index) override;
				virtual void Delete() override;
			};
		}
	}
}