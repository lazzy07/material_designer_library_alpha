#pragma once
#include "../core/DataPrimitiveFunction.hpp"

namespace MATD {
	namespace FUNC {
		namespace DATA {
			namespace OUTPUT {
				class OutputCol1 : public DataPrimitiveFunction {
				public:
					OutputCol1(MATD::GRAPH::Node* node);

					virtual void Calculate() override;
				};
			}
		}
	}
}
