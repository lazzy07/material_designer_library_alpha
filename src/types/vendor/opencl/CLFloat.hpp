#pragma once
#include "../../matd/Float.hpp"

namespace MATD {
	namespace DTYPES {
		namespace OPENCL {
			class Float : public MATD::Float {
			public:
				Float(size_t id, float val);

				virtual void Bind(const WorkItem* workItem) override;
				virtual void Delete() override;
			};
		}
	}
}