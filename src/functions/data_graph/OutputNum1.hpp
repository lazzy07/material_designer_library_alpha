#pragma once
#include "../core/DataPrimitiveOutput.hpp"

namespace MATD {
	namespace FUNC {
		namespace DATA {
			namespace OUTPUT {
				class OutputNum1 : public DataPrimitiveOutput {
				public:
					OutputNum1(MATD::GRAPH::Node* node);

					virtual void Calculate() override;
					virtual void SetSocketArguments() override;
				};
			}
		}
	}
}
