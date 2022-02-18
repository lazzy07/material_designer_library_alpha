#pragma once
#include "../core/DataPrimitiveProcess.hpp"

namespace MATD {
	namespace FUNC {
		namespace DATA {
			namespace PROCESS {
				class Col3ToNum1 : public DataPrimitiveProcess{
				public:
					Col3ToNum1(MATD::GRAPH::Node* node);

					virtual void Calculate() override;
					virtual void SetSocketArguments() override;
				};
			}
		}
	}
}