#pragma once
#include "../core/DataPrimitiveFunction.hpp"

namespace MATD {
	namespace FUNC {
		namespace DATA {
			namespace INPUT {
				class Lut1Input : public DataPrimitiveFunction {
				public:
					Lut1Input(MATD::GRAPH::Node* node);

					virtual void Calculate() override;
				};
			}
		}
	}
}