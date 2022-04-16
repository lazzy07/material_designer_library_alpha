#include "Graph.hpp"
#include "../../core/Core.hpp"
#include "../../core/Time.hpp"
#include "Connection.hpp"

MATD::GRAPH::Graph::Graph(MaterialGraph* graph, const MATD::JSON& JSONObj): m_MaterialGraph(graph)
{
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
		auto time = MATD::CORE::Time::GetTime();
		this->StartUpdate(inputNode.get(), time);
		inputNode->GetFunction()->get()->Update();
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
			
	auto time = MATD::CORE::Time::GetTime();
	auto nextNode = inputSocket->GetNode();
	this->StartUpdate(nextNode, time);

	nextNode->GetFunction()->get()->Update();
}

std::vector<MATD::Ref<MATD::GRAPH::Node>> MATD::GRAPH::Graph::GetOutputNodes()
{
	std::vector<Ref<MATD::GRAPH::Node>> outputNodes;
	auto nodes = this->GetNodes();

	for (auto ele = nodes->begin(); ele != nodes->end(); ele++) {
		auto node = ele->second;
		auto functionType = node->GetFunction()->get()->GetFunctionType();

		if (functionType == MATD::FUNC::FUNCTION_TYPE::OUTPUT) {
			outputNodes.push_back(node);
		}
	}

	return outputNodes;
}

void MATD::GRAPH::Graph::StartUpdate(Node* node, uint64_t time)
{
	auto outputSockets = node->GetOutputSockets();

	for (auto outputSocket : outputSockets) {
		if (outputSocket.second->NoOfConnections() > 0) {
			auto connections = outputSocket.second->GetConnections();

			for (auto connection : connections) {
				auto nextNode = connection.second->GetInput()->GetNode();
				if (nextNode) {
					connection.second->SetUpdateStatus(CONNECTION_UPDATE_STATUS::IN_PROGRESS, time);
					this->StartUpdate(nextNode, time);
				}
			}
		}
	}
}
