#pragma once
#include "DataPrimitiveFunction.hpp"

namespace MATD{
  namespace FUNC{
    class DataPrimitiveProcess : public DataPrimitiveFunction {
		public:
			DataPrimitiveProcess(MATD::GRAPH::Node* node);
			
			virtual void Calculate() = 0;
			virtual void SetSocketArguments() = 0;
    };
  }
}