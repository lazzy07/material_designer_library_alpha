#pragma once
#include "DataPrimitiveFunction.hpp"

namespace MATD{
  namespace FUNC{
    class DataPrimitiveOutput : public DataPrimitiveFunction {
		public:
			DataPrimitiveOutput(MATD::GRAPH::Node* node);
			
			virtual void Calculate() = 0;
			virtual void SetSocketArguments() = 0;
    };
  }
}