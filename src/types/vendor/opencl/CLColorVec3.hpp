#pragma once
#include "../../matd/MatColorVec3.hpp"

namespace MATD {
	namespace DTYPES {
		namespace OPENCL {
			class ColorVec3 : public MATD::MatColorVec3 {
			public:
				ColorVec3(MATD::ColorVec3 val);

				virtual void Bind(WorkItem* workItem, size_t index) override;
				virtual void Delete() override;
				virtual void AddToQueue(MATD::Queue* queue) override;
			};
		}
	}
}