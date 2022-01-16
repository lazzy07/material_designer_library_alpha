#pragma once
#include "../core/DataPrimitiveFunction.hpp"

namespace MATD {
	namespace FUNC {
		namespace DATA {
			namespace PROCESS {
				class SubstractNumber : public DataPrimitiveFunction {
				public:
					SubstractNumber(MATD::GRAPH::Node* node);

					virtual void Calculate() override;
					virtual void Update() override;

					virtual void OnComplete() override;
				};
			}
		}
	}
}