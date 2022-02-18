#pragma once
#include "../core/DataPrimitiveOutput.hpp"

namespace MATD {
	namespace FUNC {
		namespace DATA {
			namespace OUTPUT {
				class OutputCol1 : public DataPrimitiveOutput {
				public:
					OutputCol1(MATD::GRAPH::Node* node);

					virtual void Calculate() override;
					virtual void SetSocketArguments() override;
				};
			}
		}
	}
}
