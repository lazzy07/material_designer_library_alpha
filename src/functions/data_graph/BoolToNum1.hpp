#pragma once
#include "../core/DataPrimitiveProcess.hpp"

namespace MATD {
	namespace FUNC {
		namespace DATA {
			namespace PROCESS {
				class BoolToNum1 : public DataPrimitiveProcess {
				public:
					BoolToNum1(MATD::GRAPH::Node* node);

					virtual void Calculate() override;
					virtual void SetSocketArguments() override;
				};
			}
		}
	}
}