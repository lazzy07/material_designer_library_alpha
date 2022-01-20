#pragma once
#include "../core/DataPrimitiveFunction.hpp"

namespace MATD {
	namespace FUNC {
		namespace DATA {
			namespace PROCESS {
				class Num1ToCol1 : public DataPrimitiveFunction {
				public:
					Num1ToCol1(MATD::GRAPH::Node* node);

					virtual void Calculate() override;
				};
			}
		}
	}
}