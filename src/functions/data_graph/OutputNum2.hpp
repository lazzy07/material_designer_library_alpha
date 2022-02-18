#pragma once
#include "../core/DataPrimitiveOutput.hpp"

namespace MATD {
	namespace FUNC {
		namespace DATA {
			namespace OUTPUT {
				class OutputNum2 : public DataPrimitiveOutput {
				public:
					OutputNum2(MATD::GRAPH::Node* node);

					virtual void Calculate() override;
					virtual void SetSocketArguments() override;
				};
			}
		}
	}
}
