#pragma once
#include "DataFunction.hpp"

namespace MATD{
  namespace FUNC{
    class DataPrimitiveFunction : public DataFunction {
		public:
			DataPrimitiveFunction(MATD::GRAPH::Node* node);
			~DataPrimitiveFunction();

			virtual void Init(MATD::JSON JSONObj) override;
			virtual void Calculate() = 0;
    };
  }
}