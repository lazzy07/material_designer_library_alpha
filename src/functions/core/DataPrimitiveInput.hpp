#pragma once
#include "DataPrimitiveFunction.hpp"

namespace MATD{
  namespace FUNC{
    class DataPrimitiveInput : public DataPrimitiveFunction {
		public:
			DataPrimitiveInput(MATD::GRAPH::Node* node);
			
			virtual void Calculate() = 0;
			virtual void SetSocketArguments() = 0;
    };
  }
}