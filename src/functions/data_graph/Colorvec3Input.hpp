#pragma once
#include "../core/DataPrimitiveInput.hpp"

namespace MATD {
	namespace FUNC {
		namespace DATA {
			namespace INPUT {
				class Colorvec3Input : public DataPrimitiveInput {
				public:
					Colorvec3Input(MATD::GRAPH::Node* node);

					virtual void Calculate() override;
					virtual void SetSocketArguments() override;
				};
			}
		}
	}
}