#pragma once
#include "../../matd/MatNumber2.hpp"

namespace MATD {
	namespace DTYPES {
		namespace OPENCL {
			class Number2 : public MATD::MatNumber2 {
			public:
				Number2(MATD::Number2 val);

				virtual void Bind(WorkItem* workItem, size_t index) override;
				virtual void Delete() override;
				virtual void AddToQueue(MATD::Queue* queue) override;
			};
		}
	}
}