#include "Graph.hpp"
#include "../../core/Core.hpp"
#include "Connection.hpp"

MATD::GRAPH::Graph::Graph(MaterialGraph* graph, const MATD::JSON& JSONObj): m_MaterialGraph(graph)
{
	this->Init(JSONObj);
}

MATD::GRAPH::Graph::~Graph()
{
}

void MATD::GRAPH::Graph::RemoveNode(MATD::JSON JSONObj)
{
}

void MATD::GRAPH::Graph::AddConnection(MATD::JSON JSONObj)
{
	std::string connectionId = JSONObj["id"].get<std::string>();
	MATD::JSON outputData = JSONObj["input"]["connections"].at(0);
	MATD::JSON inputs = JSONObj["output"]["connections"];
	MATD::JSON inputData;

	MATD_CORE_WARN("{}", inputs);

	for (auto input = inputs.begin(); input<inputs.end(); input++) {
		std::string connId = input.value()["id"].get<std::string>();

		if (connId == connectionId) {
			inputData = input.value();
		}
	}

	int outputNodeID = outputData["node"].get<int>();
	int inputNodeID = inputData["node"].get<int>();

	std::string outputSocketID = outputData["output"].get<std::string>();
	std::string inputSocketID = inputData["input"].get<std::string>();

	auto outputNode = this->GetNode(outputNodeID);
	auto inputNode = this->GetNode(inputNodeID);

	auto outputSocket = outputNode->GetOutputSocket(outputSocketID);
	auto inputSocket = inputNode->GetInputSocket(inputSocketID);

	if (inputSocket && outputSocket) {
		Ref<Connection> connection = std::make_shared<Connection>(connectionId, inputSocket, outputSocket);
		outputSocket->AddConnection(connection);
		inputSocket->AddConnection(connection);
		this->AddToConnectionPool(connectionId, connection);
		outputNode->GetFunction()->get()->Update();
	}
	else {
		MATD_CORE_ERROR("Input/Output sockets cannot be null");
		MATD_CORE_ASSERT(false, "Input/Output sockets cannot be null");
	}
}

void MATD::GRAPH::Graph::RemoveConnection(MATD::JSON JSONObj)
{
	std::string connectionId = JSONObj["id"].get<std::string>();
	MATD::Ref<InputSocket> inputSocket;
	
	{
		Ref<MATD::GRAPH::Connection> connection = this->GetConnection(connectionId);
		if (connection) {
			connection->GetInput()->RemoveConnection(connectionId);
			connection->GetOutput()->RemoveConnection(connectionId);
			this->RemoveFromConnectionPool(connectionId);
			inputSocket = connection->GetInput();
		}
		else {
			MATD_CORE_ASSERT(false, "Connection not found");
		}
	}
	
	inputSocket->GetNode()->GetFunction()->get()->Update();

}

void MATD::GRAPH::Graph::Init(const MATD::JSON& JSONObj)
{
	this->m_ID = JSONObj["id"].get<std::string>();

	MATD::JSON nodes = JSONObj["data"]["nodes"];

}

