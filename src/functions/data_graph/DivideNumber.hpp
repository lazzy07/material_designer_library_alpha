#pragma once
#include "../core/DataPrimitiveProcess.hpp"

namespace MATD {
	namespace FUNC {
		namespace DATA {
			namespace PROCESS {
				class DivideNumber : public DataPrimitiveProcess {
				public:
					DivideNumber(MATD::GRAPH::Node* node);

					void Calculate() override;
					void SetSocketArguments() override;

				};
			}
		}
	}
}