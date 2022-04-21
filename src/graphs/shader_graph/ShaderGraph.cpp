#include "ShaderGraph.hpp"
#include "../core/MaterialGraph.hpp"
#include "ShaderNode.hpp"

MATD::GRAPH::ShaderGraph::ShaderGraph(MaterialGraph* graph, MATD::JSON JSONObj) : MATD::GRAPH::Graph(graph, JSONObj)
{
	this->Init(JSONObj);
	MATD_CORE_TRACE("MATD::GRAPH DataGraph created ID: {} MatGraphID: {}", this->GetID(), this->GetMaterialGraph()->GetID());
}

MATD::GRAPH::ShaderGraph::~ShaderGraph()
{
}

void MATD::GRAPH::ShaderGraph::CreateNode(MATD::JSON JSONObj)
{
	Ref<ShaderNode> shaderNode = std::make_shared<ShaderNode>(this, JSONObj);
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

void MATD::GRAPH::ShaderGraph::Init(const MATD::JSON& JSONObj)
{
	this->SetID(JSONObj["id"].get<std::string>());
	MATD::JSON nodes = JSONObj["data"]["nodes"];
}
