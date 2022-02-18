#pragma once
#include "../core/DataPrimitiveInput.hpp"

namespace MATD {
	namespace FUNC {
		namespace DATA {
			namespace INPUT {
				class Num2Input : public DataPrimitiveInput{
				public:
					Num2Input(MATD::GRAPH::Node* node);

					virtual void Calculate() override;
					virtual void SetSocketArguments() override;
				};
			}
		}
	}
}
