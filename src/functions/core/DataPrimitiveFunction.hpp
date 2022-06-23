#pragma once
#include "DataFunction.hpp"

namespace MATD{
  namespace FUNC{
    class DataPrimitiveFunction : public DataFunction {
		public:
			DataPrimitiveFunction(MATD::GRAPH::Node* node);
			~DataPrimitiveFunction();

    	void Init(MATD::JSON JSONObj) override;
			void Calculate() override = 0;
			void SetSocketArguments() override = 0;
    };
  }
}