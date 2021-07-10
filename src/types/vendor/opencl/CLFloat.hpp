#pragma once
#include "../../matd/Float.hpp"

namespace MATD {
	namespace DTYPES {
		namespace OPENCL {
			class Float : public MATD::Float {
			public:
				Float(float val);

				virtual void Bind(WorkItem* workItem, size_t index) override;
				virtual void Delete() override;
				virtual void AddToQueue(MATD::Queue* queue) override;
			};
		}
	}
}