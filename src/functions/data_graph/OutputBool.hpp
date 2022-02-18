#pragma once
#include "../core/DataPrimitiveOutput.hpp"

namespace MATD {
	namespace FUNC {
		namespace DATA {
			namespace OUTPUT {
				class OutputBool : public DataPrimitiveOutput {
				public:
					OutputBool(MATD::GRAPH::Node* node);

					virtual void Calculate() override;
					virtual void SetSocketArguments() override;
				};
			}
		}
	}
}
