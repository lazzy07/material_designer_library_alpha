#include "ShaderGraph.hpp"
#include "../core/MaterialGraph.hpp"
#include "ShaderNode.hpp"
#include "../../core/MaterialDesigner.hpp"

MATD::GRAPH::ShaderGraph::ShaderGraph(MaterialGraph* graph, MATD::JSON JSONObj) : MATD::GRAPH::Graph(graph, JSONObj)
{
	this->Init(JSONObj);
	MATD_CORE_TRACE("MATD::GRAPH ShaderGraph created ID: {} MatGraphID: {}", this->GetID(), this->GetMaterialGraph()->GetID());
}

MATD::GRAPH::ShaderGraph::~ShaderGraph()
{
}

void MATD::GRAPH::ShaderGraph::CreateNode(MATD::JSON JSONObj)
{
	const Ref<ShaderNode> shaderNode = std::make_shared<ShaderNode>(this, JSONObj);
	const unsigned int id = JSONObj["id"].get<int>();
	this->SetNode(id, shaderNode);
	shaderNode->Init();
}

void MATD::GRAPH::ShaderGraph::Update(MATD::JSON JSONObj)
{
	MATD_CORE_INFO("MATD::GRAPH Parameter change recieved of ShaderGraph : {}", this->GetID());
	MATD::JSON payload = JSONObj["payload"];
	std::string selectedType = payload["selectedType"].get<std::string>();

	int id = payload["data"]["id"].get<int>();
	auto node = this->GetNode(id);

	node->UpdateParameters(payload["data"]["data"]["dataGraph"]["data"]);

	node->SetJSON(payload["data"]);
}

void MATD::GRAPH::ShaderGraph::RemoveNode(MATD::JSON JSONObj)
{
	
}

void MATD::GRAPH::ShaderGraph::AddConnection(MATD::JSON JSONObj)
{
	Graph::AddConnection(JSONObj);
}

void MATD::GRAPH::ShaderGraph::RemoveConnection(MATD::JSON JSONObj)
{
	Graph::RemoveConnection(JSONObj);
}
