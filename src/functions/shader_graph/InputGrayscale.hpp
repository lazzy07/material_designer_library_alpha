#pragma once

#include "../core/ShaderPrimitiveInput.hpp"

namespace MATD {
	namespace FUNC {
		namespace SHADER {
			namespace INPUT {
        class InputGrayscale : public ShaderPrimitiveInput {
					InputGrayscale(MATD::GRAPH::Node* node);

					virtual void Calculate() override;
					virtual void SetSocketArguments() override;
        };
      }
    }
  }
}