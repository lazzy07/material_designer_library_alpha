#pragma once
#include "../core/DataPrimitiveFunction.hpp"

namespace MATD {
	namespace FUNC {
		namespace DATA {
			namespace PROCESS {
				class SqrtNumber : public DataPrimitiveFunction {
				public:
					SqrtNumber(MATD::GRAPH::Node* node);

					virtual void Calculate() override;
				};
			}
		}
	}
}