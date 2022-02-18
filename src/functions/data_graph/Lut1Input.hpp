#pragma once
#include "../core/DataPrimitiveInput.hpp"

namespace MATD {
	namespace FUNC {
		namespace DATA {
			namespace INPUT {
				class Lut1Input : public DataPrimitiveInput {
				public:
					Lut1Input(MATD::GRAPH::Node* node);

					virtual void Calculate() override;
					virtual void SetSocketArguments() override;
				};
			}
		}
	}
}