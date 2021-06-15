#pragma once
#include "../../matd/Int.hpp"

namespace MATD {
	namespace DTYPES {
		namespace OPENCL {
			class Int : public MATD::Int {
			public:
				Int(int val);

				virtual void Bind(const ENGINE::WorkItem* workItem, size_t index) override;
				virtual void Delete() override;
			};
		}
	}
}