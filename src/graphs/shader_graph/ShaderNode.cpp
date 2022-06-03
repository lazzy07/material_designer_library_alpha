#include "ShaderNode.hpp"
#include "../core/Graph.hpp"
#include "../../functions/core/ShaderPrimitiveFunction.hpp"
#include "../../functions/core/Argument.hpp"
#include <memory>

MATD::GRAPH::ShaderNode::ShaderNode(Graph* graph, MATD::JSON JSONObj) : MATD::GRAPH::Node(graph, JSONObj)
{
	MATD_CORE_TRACE("MATD::GRAPH ShaderNode created, ID: {}", this->GetID());
}

MATD::GRAPH::ShaderNode::~ShaderNode()
{
}

void MATD::GRAPH::ShaderNode::Init()
{
	const MATD::JSON JSONObj = *this->GetJSON();
	std::string name = JSONObj["name"].get<std::string>();
	MATD::JSON sGraphData = JSONObj["data"]["dataGraph"];
	std::string initialID = sGraphData["parentId"].get<std::string>();

	if (sGraphData["ioType"].is_string()) {
		std::string ioType = sGraphData["ioType"].get<std::string>();

		if (ioType.length() > 0) {
			//A primitive function
			MATD::JSON dataArr = sGraphData["data"];
			auto function = MATD::FUNC::ShaderPrimitiveFunction::FunctionFactory(this, initialID, sGraphData);
			this->SetFunction(function);
			this->GetFunction()->get()->Init(sGraphData);
			return;
		}
	}
	//Not a primitive function
	MATD::JSON graphData = sGraphData["data"];
}

void MATD::GRAPH::ShaderNode::UpdateParameters(JSON JSONObj)
{
	for (auto it = JSONObj.begin(); it != JSONObj.end(); ++it) {
		MATD::JSON argData = it.value();
		std::string id = argData["id"].get<std::string>();
		auto arg = this->GetFunction()->get()->GetArgument(id);

		arg->SetData(argData);
		MATD_CORE_TRACE("MATD::GRAPH Argument data changed ID: {}", arg->GetID());
	}

	const auto time = MATD::CORE::Time::GetTime();
	this->GetGraph()->StartUpdate(this, time);
	this->GetFunction()->get()->Update();
}
