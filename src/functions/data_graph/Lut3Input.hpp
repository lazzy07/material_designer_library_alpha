#pragma once
#include "../core/DataPrimitiveInput.hpp"

namespace MATD {
	namespace FUNC {
		namespace DATA {
			namespace INPUT {
				class Lut3Input : public DataPrimitiveInput {
				public:
					Lut3Input(MATD::GRAPH::Node* node);

					virtual void Calculate() override;
					virtual void SetSocketArguments() override;
				};
			}
		}
	}
}