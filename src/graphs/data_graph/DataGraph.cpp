#include "DataGraph.hpp"
#include "../../core/Core.hpp"
#include "../core/MaterialGraph.hpp"
#include "DataNode.hpp"

MATD::GRAPH::DataGraph::DataGraph(MaterialGraph* graph, const MATD::JSON& JSONObj) : MATD::GRAPH::Graph(graph, JSONObj)
{
	MATD_CORE_TRACE("MATD::GRAPH DataGraph created ID: {} MatGraphID: {}", this->GetID(), this->GetMaterialGraph()->GetID());
}

MATD::GRAPH::DataGraph::~DataGraph()
{
}

void MATD::GRAPH::DataGraph::CreateNode(MATD::JSON JSONObj)
{
	Ref<DataNode> dataNode = std::make_shared<DataNode>(this, JSONObj);
	const unsigned int id = JSONObj["id"].get<int>();
	this->m_Nodes[id] = dataNode;
}

void MATD::GRAPH::DataGraph::RemoveNode(MATD::JSON JSONObj)
{
	MATD_CORE_TRACE("Remove Node {}", JSONObj);
}

void MATD::GRAPH::DataGraph::AddConnection(MATD::JSON JSONObj)
{
	MATD_CORE_TRACE("Add Connection {}", JSONObj);
}

void MATD::GRAPH::DataGraph::RemoveConnection(MATD::JSON JSONObj)
{
	MATD_CORE_TRACE("Remove Connection {}", JSONObj);
}

void MATD::GRAPH::DataGraph::Update(MATD::JSON JSONObj)
{
	MATD_CORE_TRACE("Update {}", JSONObj);
}
