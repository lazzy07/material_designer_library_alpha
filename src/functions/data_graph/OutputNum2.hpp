#pragma once
#include "../core/DataPrimitiveFunction.hpp"

namespace MATD {
	namespace FUNC {
		namespace DATA {
			namespace OUTPUT {
				class OutputNum2 : public DataPrimitiveFunction {
				public:
					OutputNum2(MATD::GRAPH::Node* node);

					virtual void Calculate() override;
					virtual void Update() override;

					virtual void OnComplete() override;
				};
			}
		}
	}
}
