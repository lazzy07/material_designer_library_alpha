#pragma once
#include "../core/ShaderPrimitiveOutput.hpp"

namespace MATD {
	namespace FUNC {
		namespace SHADER {
			namespace OUTPUT {
        class OutputColor : public ShaderPrimitiveOutput {
					OutputColor(MATD::GRAPH::Node* node);

					virtual void Calculate() override;
					virtual void SetSocketArguments() override;
        };
      }
    }
  }
}