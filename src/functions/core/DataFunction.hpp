#pragma once
#include "Function.hpp"

namespace MATD{
  namespace FUNC{
    class DataFunction : public Function {
    public:
      DataFunction(MATD::GRAPH::Node* node);
      ~DataFunction();

			virtual void Init(MATD::JSON JSONObj) = 0;
			virtual void Calculate() = 0;
			virtual void Update() = 0;

			virtual void OnComplete() = 0;
    };
  }
}