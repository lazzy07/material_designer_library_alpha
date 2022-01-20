#pragma once
#include "../core/DataPrimitiveFunction.hpp"

namespace MATD {
	namespace FUNC {
		namespace DATA {
			namespace INPUT {
				class Lut3Input : public DataPrimitiveFunction {
				public:
					Lut3Input(MATD::GRAPH::Node* node);

					virtual void Calculate() override;
				};
			}
		}
	}
}