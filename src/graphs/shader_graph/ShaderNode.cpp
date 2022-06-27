#include "ShaderNode.hpp"
#include "../core/Graph.hpp"
#include "../../functions/core/ShaderPrimitiveFunction.hpp"
#include "../../functions/shader_graph/ShaderGraphNode.hpp"
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
	auto name = JSONObj["name"].get<std::string>();
	MATD::JSON dGraphData = JSONObj["data"]["dataGraph"];
	const std::string initialID = dGraphData["parentId"].get<std::string>();

	if (!dGraphData["isSecondary"].is_boolean() || !dGraphData["isSecondary"].get<bool>()) {
		const std::string ioType = dGraphData["ioType"].get<std::string>();

		if (ioType.length() > 0) {
			//A primitive function
			MATD::JSON dataArr = dGraphData["data"];
			const auto function = MATD::FUNC::ShaderPrimitiveFunction::FunctionFactory(this, initialID, dGraphData);

			this->SetFunction(function);
			return;
		}
	}
	//Not a primitive function
	const auto func = std::make_shared<MATD::FUNC::SHADER::PROCESS::ShaderGraphNode>(this);
	func->Init(JSONObj);
	this->SetFunction(func);
}

void MATD::GRAPH::ShaderNode::UpdateParameters(JSON JSONObj, int subNodeId)
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
