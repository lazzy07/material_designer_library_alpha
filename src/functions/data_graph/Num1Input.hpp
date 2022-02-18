#pragma once
#include "../core/DataPrimitiveInput.hpp"

namespace MATD{
  namespace FUNC{
    namespace DATA{
      namespace INPUT{
        class Num1Input : public DataPrimitiveInput{
        public:
          Num1Input(MATD::GRAPH::Node* node);

					virtual void Calculate() override;
					virtual void SetSocketArguments() override;
        };
      }
    }
  }
}