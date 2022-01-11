#pragma once
#include "../core/DataPrimitiveFunction.hpp"

namespace MATD{
  namespace FUNC{
    namespace DATA{
      namespace INPUT{
        class Number1Input : public DataPrimitiveFunction{
        public:
          Number1Input(MATD::GRAPH::Node* node);

					virtual void Calculate() override;
					virtual void Update() override;

					virtual void OnComplete() override;
        };
      }
    }
  }
}