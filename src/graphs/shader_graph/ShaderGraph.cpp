#include "ShaderGraph.hpp"
#include "../core/MaterialGraph.hpp"

MATD::GRAPH::ShaderGraph::ShaderGraph(MaterialGraph* graph, const MATD::JSON& JSONObj) : MATD::GRAPH::Graph(graph, JSONObj)
{
	MATD_CORE_TRACE("MATD::GRAPH SataGraph created ID: {} MatGraphID: {}", this->GetID(), this->GetMaterialGraph()->GetID());
}

MATD::GRAPH::ShaderGraph::~ShaderGraph()
{
}

void MATD::GRAPH::ShaderGraph::CreateNode(MATD::JSON JSONObj)
{
}

void MATD::GRAPH::ShaderGraph::RemoveNode(MATD::JSON JSONObj)
{
}

void MATD::GRAPH::ShaderGraph::AddConnection(MATD::JSON JSONObj)
{
}

void MATD::GRAPH::ShaderGraph::RemoveConnection(MATD::JSON JSONObj)
{
}

void MATD::GRAPH::ShaderGraph::Update(MATD::JSON JSONObj)
{
}
