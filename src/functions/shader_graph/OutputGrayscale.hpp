#pragma once

#include "../core/ShaderPrimitiveOutput.hpp"

namespace MATD {
	namespace FUNC {
		namespace SHADER {
			namespace OUTPUT {
        class OutputGrayscale : public ShaderPrimitiveOutput {
				public:
					OutputGrayscale(MATD::GRAPH::Node* node);

					virtual void Calculate() override;
					virtual void SetSocketArguments() override;
        };
      }
    }
  }
}