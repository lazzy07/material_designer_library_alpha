#pragma once
#include "../core/ShaderPrimitiveInput.hpp"

namespace MATD {
	namespace FUNC {
		namespace SHADER {
			namespace INPUT {
        class InputColor : public ShaderPrimitiveInput {
          InputColor(MATD::GRAPH::Node* node);

					virtual void Calculate() override;
					virtual void SetSocketArguments() override;
        };
      }
    }
  }
}