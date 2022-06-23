#include "DataNode.hpp"
#include "../core/Graph.hpp"
#include "../../functions/core/DataPrimitiveFunction.hpp"
#include "../../functions/data_graph/DataGraphNode.hpp"
#include "../../functions/core/Argument.hpp"
#include "../core/InputSocket.hpp"
#include "../core/Connection.hpp"

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
	auto name = JSONObj["name"].get<std::string>();
	MATD::JSON dGraphData = JSONObj["data"]["dataGraph"];
	const std::string initialID = dGraphData["parentId"].get<std::string>();

	if (!dGraphData["isSecondary"].is_boolean() || !dGraphData["isSecondary"].get<bool>()) {
		const std::string ioType = dGraphData["ioType"].get<std::string>();

		if (ioType.length() > 0) {
			//A primitive function
			MATD::JSON dataArr = dGraphData["data"];
			const auto function = MATD::FUNC::DataPrimitiveFunction::FunctionFactory(this, initialID, dGraphData);
			
			this->SetFunction(function);
			return;
		}
	}
	//Not a primitive function
	const auto func = std::make_shared<MATD::FUNC::DATA::PROCESS::DataGraphNode>(this);
	func->Init(JSONObj);
	this->SetFunction(func);
}

void MATD::GRAPH::DataNode::UpdateParameters(JSON JSONObj, int subNodeId)
{
	if(this->GetIsPrimitive())
	{
		for (auto it = JSONObj.begin(); it != JSONObj.end(); ++it) {
			MATD::JSON argData = it.value();
			std::string id = argData["id"].get<std::string>();
			const auto arg = this->GetFunction()->get()->GetArgument(id);
			if(arg)
			{
				arg->SetData(argData);
				MATD_CORE_TRACE("MATD::GRAPH Argument data changed ID: {}", arg->GetID());
			}else
			{
				MATD_CORE_WARN("MATD::GRAPH Argument not found {}", id);
			}
		}
	}else{
		//the node is not a primitive node, hence data have graphData
		const auto nodes = JSONObj["nodes"];
		const auto nodeData = nodes[std::to_string(subNodeId)];

		const auto func = dynamic_cast<MATD::FUNC::DATA::PROCESS::DataGraphNode*>
		(this->GetFunction()->get());

		const auto materialGraph = func->GetMaterialGraph();
		const auto node = materialGraph->GetGraph(GRAPH_TYPE::DATA_GRAPH)->GetNode(subNodeId);

		if(const auto function = node->GetFunction()->get())
		{
			if(function->GetFunctionType() == FUNC::FUNCTION_TYPE::INPUT)
			{
				node->UpdateParameters(nodeData["data"]["dataGraph"]["data"]);
			}
		}
	}
	

 	const auto time = MATD::CORE::Time::GetTime();
	this->GetGraph()->StartUpdate(this, time);
	this->GetFunction()->get()->Update();
}
