#pragma once
#include "../core/DataPrimitiveFunction.hpp"

namespace MATD {
	namespace FUNC {
		namespace DATA {
			namespace PROCESS {
				class Num1ToNum2 : public DataPrimitiveFunction {
				public:
					Num1ToNum2(MATD::GRAPH::Node* node);

					virtual void Calculate() override;
					virtual void Update() override;

					virtual void OnComplete() override;
				};
			}
		}
	}
}