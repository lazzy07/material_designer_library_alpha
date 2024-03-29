#include "DataGraph.hpp"
#include "../../core/Core.hpp"
#include "../core/MaterialGraph.hpp"
#include "DataNode.hpp"
#include "../core/Connection.hpp"

MATD::GRAPH::DataGraph::DataGraph(MaterialGraph* graph, const MATD::JSON& JSONObj) : MATD::GRAPH::Graph(graph, JSONObj)
{
	this->Init(JSONObj);
	MATD_CORE_TRACE("MATD::GRAPH DataGraph created ID: {} MatGraphID: {}", this->GetID(), this->GetMaterialGraph()->GetID());
}

MATD::GRAPH::DataGraph::~DataGraph()
{
}

void MATD::GRAPH::DataGraph::CreateNode(MATD::JSON JSONObj)
{
	Ref<DataNode> dataNode = std::make_shared<DataNode>(this, JSONObj);
	const unsigned int id = JSONObj["id"].get<int>();
	this->SetNode(id, dataNode);
}

void MATD::GRAPH::DataGraph::Update(MATD::JSON JSONObj)
{
	MATD_CORE_INFO("MATD::GRAPH Parameter change recieved of DataGraph : {}", this->GetID());
	MATD::JSON payload = JSONObj["payload"];
	auto selectedType = payload["selectedType"].get<std::string>();

	int id = payload["data"]["id"].get<int>();
	const auto node = this->GetNode(id);

	node->UpdateParameters(payload["data"]["data"]["dataGraph"]["data"], payload.contains("subNodeId") ? payload["subNodeId"].get<int>() : NULL);
	node->SetJSON(payload["data"]);
}
