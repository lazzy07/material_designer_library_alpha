#pragma once
#include "../core/DataPrimitiveFunction.hpp"

namespace MATD {
	namespace FUNC {
		namespace DATA {
			namespace INPUT {
				class Colorvec1Input : public DataPrimitiveFunction {
				public:
					Colorvec1Input(MATD::GRAPH::Node* node);

					virtual void Calculate() override;
				};
			}
		}
	}
}