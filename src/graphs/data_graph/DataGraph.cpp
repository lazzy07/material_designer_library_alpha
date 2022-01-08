#include "DataGraph.hpp"
#include "../../core/Core.hpp"
#include "../core/MaterialGraph.hpp"

MATD::GRAPH::DataGraph::DataGraph(MaterialGraph* graph, const MATD::JSON& JSONObj) : MATD::GRAPH::Graph(graph, JSONObj)
{
	MATD_CORE_TRACE("MATD::GRAPH DataGraph created ID: {} MatGraphID: {}", this->GetID(), this->GetMaterialGraph()->GetID());
}

MATD::GRAPH::DataGraph::~DataGraph()
{
}

void MATD::GRAPH::DataGraph::CreateNode(MATD::JSON JSONObj)
{
}

void MATD::GRAPH::DataGraph::RemoveNode(MATD::JSON JSONObj)
{
}

void MATD::GRAPH::DataGraph::AddConnection(MATD::JSON JSONObj)
{
}

void MATD::GRAPH::DataGraph::RemoveConnection(MATD::JSON JSONObj)
{
}

void MATD::GRAPH::DataGraph::Update(MATD::JSON JSONObj)
{
}
