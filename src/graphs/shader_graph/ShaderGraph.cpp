#include "ShaderGraph.hpp"
#include "../core/MaterialGraph.hpp"

MATD::GRAPH::ShaderGraph::ShaderGraph(MaterialGraph* graph, const MATD::JSON& JSONObj) : MATD::GRAPH::Graph(graph, JSONObj)
{
	MATD_CORE_TRACE("MATD::GRAPH SataGraph created ID: {} MatGraphID: {}", this->GetID(), this->GetMaterialGraph()->GetID());
}

MATD::GRAPH::ShaderGraph::~ShaderGraph()
{
}

void MATD::GRAPH::ShaderGraph::Update(MATD::JSON JSONObj)
{
}