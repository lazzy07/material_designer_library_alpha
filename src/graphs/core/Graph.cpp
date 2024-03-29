#include "Graph.hpp"
#include "../../core/Core.hpp"
#include "../../core/Time.hpp"
#include "../../core/MaterialDesigner.hpp"
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

	for (auto input = inputs.begin(); input<inputs.end(); ++input) {
		if (std::string connId = input.value()["id"].get<std::string>(); connId == connectionId) {
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
	const std::string connectionId = JSONObj["id"].get<std::string>();

	const Ref<MATD::GRAPH::Connection> connection = this->GetConnection(connectionId);

	{
		if (connection) {
			connection->GetInput()->RemoveConnection(connectionId);
			connection->GetOutput()->RemoveConnection(connectionId);

			this->RemoveFromConnectionPool(connectionId);
			const MATD::Ref<InputSocket> inputSocket = connection->GetInput();

			const auto time = MATD::CORE::Time::GetTime();
			const auto nextNode = inputSocket->GetNode();
			this->StartUpdate(nextNode, time);

			nextNode->GetFunction()->get()->Update();
		}
		else {
			MATD_CORE_WARN("Connection not found");
		}
	}

}

void MATD::GRAPH::Graph::Init(MATD::JSON JSONObj)
{
	this->SetID(JSONObj["id"].get<std::string>());
	MATD::JSON nodes = JSONObj["data"]["nodes"];

	for(auto& [key, nodeJson] : nodes.items())
	{
		this->CreateNode(nodeJson);
	}

	for(auto& [nodeId, nodeJson] : nodes.items())
	{
		//Check input sockets and add connections (No need to check output nodes)
		for(auto& [socketId, socket] : nodeJson["inputs"].items())
		{
			auto& connections = socket["connections"];
			for(auto& connection: connections)
			{
				int inputNodeId = std::stoi(nodeId);
				auto outputNodeId = connection["node"].get<int>();
				
				auto inputSocket = this->GetNode(inputNodeId)->GetInputSocket(socketId);

				auto outputSocketId = connection["output"].get<std::string>();
				auto outputSocket = this->GetNode(outputNodeId)->GetOutputSocket(outputSocketId);
				auto connectionId = connection["id"].get<std::string>();

				if (inputSocket && outputSocket) {
					auto connectionPtr = std::make_shared<Connection>(connectionId, inputSocket, outputSocket);
					outputSocket->AddConnection(connectionPtr);
					inputSocket->AddConnection(connectionPtr);
					this->AddToConnectionPool(connectionId, connectionPtr);
				}
			}
		}
	}
}

std::vector<MATD::Ref<MATD::GRAPH::Node>> MATD::GRAPH::Graph::GetOutputNodes()
{
	std::vector<Ref<MATD::GRAPH::Node>> outputNodes;
	const auto nodes = this->GetNodes();

	for (const auto& [fst, node] : *nodes)
	{
		if (const auto functionType = node->GetFunction()->get()->GetFunctionType(); functionType == MATD::FUNC::FUNCTION_TYPE::OUTPUT) {
			outputNodes.push_back(node);
		}
	}

	return outputNodes;
}

std::vector<MATD::Ref<MATD::GRAPH::Node>> MATD::GRAPH::Graph::GetInputNodes()
{
	std::vector<Ref<MATD::GRAPH::Node>> inputNodes;
	const auto nodes = this->GetNodes();

	for (const auto& [fst, node] : *nodes)
	{
		if (const auto functionType = node->GetFunction()->get()->GetFunctionType(); functionType == MATD::FUNC::FUNCTION_TYPE::INPUT) {
			inputNodes.push_back(node);
		}
	}

	return inputNodes;
}

void MATD::GRAPH::Graph::StartUpdate(Node* node, uint64_t time)
{
	const auto outputSockets = node->GetOutputSockets();

	for (const auto [fst, snd] : outputSockets) {
		if (snd->NoOfConnections() > 0) {
			auto connections = snd->GetConnections();

			for (const auto& [fst, snd] : connections) {
				if (const auto nextNode = snd->GetInput()->GetNode()) {
					snd->SetUpdateStatus(CONNECTION_UPDATE_STATUS::IN_PROGRESS, time);
					this->StartUpdate(nextNode, time);
				}
			}
		}
	}
}
