#include "KernelGraph.hpp"
#include "../core/MaterialGraph.hpp"

MATD::GRAPH::KernelGraph::KernelGraph(MATD::GRAPH::MaterialGraph* graph,const MATD::JSON& JSONObj) : MATD::GRAPH::Graph(graph, JSONObj)
{
	this->Init(JSONObj);
	MATD_CORE_TRACE("MATD::GRAPH KernelGraph created ID: {} MatGraphID: {}", this->GetID(), this->GetMaterialGraph()->GetID());
}

MATD::GRAPH::KernelGraph::~KernelGraph()
{
}

void MATD::GRAPH::KernelGraph::CreateNode(MATD::JSON JSONObj)
{
}

void MATD::GRAPH::KernelGraph::Update(MATD::JSON JSONObj)
{
	MATD_CORE_TRACE("Kernel update {}", JSONObj);
	std::string type = JSONObj["type"].get<std::string>();
	std::string update = JSONObj["update"].get<std::string>();

	if (update == "kernel") {
		m_KernelSource = update;
	}
	else if (update == "functions") {
		m_FunctionsSource = update;
	}
}

void MATD::GRAPH::KernelGraph::Init(const MATD::JSON& JSONObj)
{
	this->SetID(JSONObj["id"].get<std::string>());
	m_KernelSource = JSONObj["data"]["kernel"].get<std::string>();
	m_KernelSource = JSONObj["data"]["functions"].get<std::string>();
}

void MATD::GRAPH::KernelGraph::Compile()
{
	auto materialGraph = this->GetMaterialGraph();
	
	auto dataGraph = materialGraph->GetGraph(GRAPH_TYPE::DATA_GRAPH);
	auto shaderGraph = materialGraph->GetGraph(GRAPH_TYPE::SHADER_GRAPH);

	{

	}
}
