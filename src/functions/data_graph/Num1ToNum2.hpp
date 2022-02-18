#pragma once
#include "../core/DataPrimitiveProcess.hpp"

namespace MATD {
	namespace FUNC {
		namespace DATA {
			namespace PROCESS {
				class Num1ToNum2 : public DataPrimitiveProcess {
				public:
					Num1ToNum2(MATD::GRAPH::Node* node);

					virtual void Calculate() override;
					virtual void SetSocketArguments() override;
				};
			}
		}
	}
}