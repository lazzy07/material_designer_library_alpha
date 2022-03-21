#pragma once

#include "../core/ShaderPrimitiveProcess.hpp"

namespace MATD {
	namespace FUNC {
		namespace SHADER {
			namespace PROCESS {
        class Viewer : public ShaderPrimitiveProcess {
					Viewer(MATD::GRAPH::Node* node);

					virtual void Calculate() override;
					virtual void SetSocketArguments() override;
        };
      }
    }
  }
}