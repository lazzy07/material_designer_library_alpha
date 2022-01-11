#include "DataNode.hpp"
#include "../../functions/core/DataPrimitiveFunction.hpp"

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

void MATD::GRAPH::DataNode::Update(JSON JSONObj)
{
}
