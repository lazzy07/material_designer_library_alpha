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
	const unsigned int id = JSONObj["id"].get<int>();
	std::string name = JSONObj["name"].get<std::string>();
	MATD::JSON dGraphData = JSONObj["data"]["dataGraph"];
	std::string initialID = dGraphData["parentId"].get<std::string>();

	if (dGraphData["ioType"].is_string()) {
		std::string ioType = dGraphData["ioType"].get<std::string>();

		if (ioType.length() > 0) {
			//A primitive node
			MATD::JSON dataArr = dGraphData["data"];

			return;
		}
	}
	//Not a primitive node
	MATD::JSON graph = dGraphData["data"];

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
