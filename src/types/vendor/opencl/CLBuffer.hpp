#pragma once
#include "../../matd/Buffer.hpp"

namespace MATD {
	namespace DTYPES {
		namespace OPENCL {
			class Buffer : public MATD::Buffer {
			public:
				Buffer(void* buffer, size_t size, size_t elem_size);

				virtual void Bind(const WorkItem* workItem, size_t index) override;
				virtual void Delete() override;
			};
		}
	}
}