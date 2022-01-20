#pragma once
#include "../core/DataPrimitiveFunction.hpp"

namespace MATD {
	namespace FUNC {
		namespace DATA {
			namespace PROCESS {
				class Num2ToNum1 : public DataPrimitiveFunction {
				public:
					Num2ToNum1(MATD::GRAPH::Node* node);

					virtual void Calculate() override;
				};
			}
		}
	}
}