#include "DataNode.hpp"
#include "../../functions/core/DataPrimitiveFunction.hpp"
#include "../../functions/core/Argument.hpp"

MATD::GRAPH::DataNode::DataNode(Graph* graph,JSON JSONObj) : Node(graph, JSONObj)
{
	MATD_CORE_TRACE("MATD::GRAPH DataNode created, ID: {}", this->GetID());
	this->Init();
}

MATD::GRAPH::DataNode::~DataNode()
{
}

void MATD::GRAPH::DataNode::Init()
{
	const MATD::JSON JSONObj = *this->GetJSON();
	std::string name = JSONObj["name"].get<std::string>();
	MATD::JSON dGraphData = JSONObj["data"]["dataGraph"];
	std::string initialID = dGraphData["parentId"].get<std::string>();

	if (dGraphData["ioType"].is_string()) {
		std::string ioType = dGraphData["ioType"].get<std::string>();

		if (ioType.length() > 0) {
			//A primitive function
			MATD::JSON dataArr = dGraphData["data"];
			auto function = MATD::FUNC::DataPrimitiveFunction::FunctionFactory(this, initialID, dGraphData);
			
			this->SetFunction(function);
			return;
		}
	}
	//Not a primitive function
	MATD::JSON graphData = dGraphData["data"];
}

void MATD::GRAPH::DataNode::UpdateParameters(JSON JSONObj)
{
	for (auto it = JSONObj.begin(); it != JSONObj.end(); ++it) {
		MATD::JSON argData = it.value();
		std::string id = argData["id"].get<std::string>();
		auto arg = this->GetFunction()->get()->GetArgument(id);

		arg->SetData(argData);
		MATD_CORE_TRACE("MATD::GRAPH Argument data changed ID: {}", arg->GetID());
	}
	this->GetFunction()->get()->Update();
}
