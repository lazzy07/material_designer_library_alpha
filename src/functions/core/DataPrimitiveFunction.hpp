#pragma once
#include "DataFunction.hpp"

namespace MATD{
  namespace FUNC{
    class DataPrimitiveFunction : public DataFunction {
		public:
			DataPrimitiveFunction(MATD::GRAPH::Node* node);
			~DataPrimitiveFunction();

    	void Init(MATD::JSON JSONObj) override;
			virtual void Calculate() = 0;
			virtual void SetSocketArguments() = 0;
    };
  }
}