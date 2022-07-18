#pragma once
#include "../core/DataPrimitiveFunction.hpp"

namespace MATD::FUNC::DATA::OUTPUT {
	class DataRef : public DataPrimitiveFunction
	{
	public:
		explicit DataRef(MATD::GRAPH::Node* node);
		void Init(MATD::JSON JSONObj) override;

		void Calculate() override;
		void SetSocketArguments() override;
	};
}