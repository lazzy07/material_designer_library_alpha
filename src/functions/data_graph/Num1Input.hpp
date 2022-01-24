#pragma once
#include "../core/DataPrimitiveFunction.hpp"

namespace MATD{
  namespace FUNC{
    namespace DATA{
      namespace INPUT{
        class Num1Input : public DataPrimitiveFunction{
        public:
          Num1Input(MATD::GRAPH::Node* node);

					virtual void Calculate() override;
					virtual void SetSocketArguments() override;
        };
      }
    }
  }
}