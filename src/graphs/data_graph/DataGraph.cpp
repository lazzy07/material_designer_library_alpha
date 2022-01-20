#include "DataGraph.hpp"
#include "../../core/Core.hpp"
#include "../core/MaterialGraph.hpp"
#include "DataNode.hpp"
#include "../core/Connection.hpp"

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
	std::string connectionId = JSONObj["id"].get<std::string>();
	MATD::JSON inputData = JSONObj["input"]["connections"].at(0);
	MATD::JSON outputData = JSONObj["output"]["connections"].at(0);

	int inputNodeID = inputData["node"].get<int>();
	int outputNodeID = outputData["node"].get<int>();

	std::string outputSocketID = outputData["input"].get<std::string>();

	auto output = this->GetNode(inputNodeID)->GetOutput();
	auto input = this->GetNode(outputNodeID)->GetInput(outputSocketID);

	Ref<MATD::GRAPH::Connection> connection = std::make_shared<MATD::GRAPH::Connection>(connectionId, input, output);
}

void MATD::GRAPH::DataGraph::RemoveConnection(MATD::JSON JSONObj)
{
	MATD_CORE_TRACE("Remove Connection {}", JSONObj);
}

void MATD::GRAPH::DataGraph::Update(MATD::JSON JSONObj)
{
	MATD_CORE_TRACE("Update {}", JSONObj);
}
