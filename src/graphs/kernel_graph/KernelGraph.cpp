#include "KernelGraph.hpp"
#include "../core/MaterialGraph.hpp"

MATD::GRAPH::KernelGraph::KernelGraph(MATD::GRAPH::MaterialGraph* graph,const MATD::JSON& JSONObj) : MATD::GRAPH::Graph(graph, JSONObj)
{
	MATD_CORE_TRACE("MATD::GRAPH KernelGraph created ID: {} MatGraphID: {}", this->GetID(), this->GetMaterialGraph()->GetID());
}

MATD::GRAPH::KernelGraph::~KernelGraph()
{
}

void MATD::GRAPH::KernelGraph::Update(MATD::JSON JSONObj)
{
}
