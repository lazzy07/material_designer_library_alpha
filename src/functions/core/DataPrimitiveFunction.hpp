#pragma once
#include "DataFunction.hpp"

namespace MATD{
  namespace FUNC{
    class DataPrimitiveFunction : public DataFunction {
		public:
			DataPrimitiveFunction(MATD::GRAPH::Node* node);
			~DataPrimitiveFunction();

			virtual void Init(const MATD::JSON& JSONObj) override;
			virtual void Calculate() = 0;
			virtual void Update() = 0;

			virtual void OnComplete() = 0;
    };
  }
}