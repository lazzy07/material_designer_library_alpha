#include "ShaderGraph.hpp"
#include "../core/MaterialGraph.hpp"

MATD::GRAPH::ShaderGraph::ShaderGraph(MaterialGraph* graph, const MATD::JSON& JSONObj) : MATD::GRAPH::Graph(graph, JSONObj)
{
	this->Init(JSONObj);
	MATD_CORE_TRACE("MATD::GRAPH DataGraph created ID: {} MatGraphID: {}", this->GetID(), this->GetMaterialGraph()->GetID());
}

MATD::GRAPH::ShaderGraph::~ShaderGraph()
{
}

void MATD::GRAPH::ShaderGraph::CreateNode(MATD::JSON JSONObj)
{
}

void MATD::GRAPH::ShaderGraph::Update(MATD::JSON JSONObj)
{
}

void MATD::GRAPH::ShaderGraph::Init(const MATD::JSON& JSONObj)
{
	this->SetID(JSONObj["id"].get<std::string>());
	MATD::JSON nodes = JSONObj["data"]["nodes"];
}
