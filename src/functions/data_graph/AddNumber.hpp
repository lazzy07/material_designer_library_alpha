#pragma once
#include "../core/DataPrimitiveProcess.hpp"

namespace MATD {
	namespace FUNC {
		namespace DATA {
			namespace PROCESS {
				class AddNumber : public DataPrimitiveProcess {
				public:
					AddNumber(MATD::GRAPH::Node* node);

					virtual void Calculate() override;
					virtual void SetSocketArguments() override;
				};
			}
		}
	}
}