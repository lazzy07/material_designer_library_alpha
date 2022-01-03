#include "Graph.hpp"
#include "../core/Core.hpp"

MATD::GRAPH::Graph::Graph(MaterialGraph* graph, const MATD::JSON& JSONObj): m_MaterialGraph(graph)
{
	this->Init(JSONObj);
}

MATD::GRAPH::Graph::~Graph()
{
}

void MATD::GRAPH::Graph::Init(const MATD::JSON& JSONObj)
{
	this->m_ID = JSONObj["id"].get<std::string>();

	MATD::JSON nodes = JSONObj["data"]["nodes"];

}

