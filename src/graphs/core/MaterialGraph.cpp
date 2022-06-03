#include "MaterialGraph.hpp"
#include "MaterialProject.hpp"

MATD::GRAPH::MaterialGraph::MaterialGraph(MaterialProject* project, const MATD::JSON& JSONObj) : m_Project(project), m_IsInitializedByGraph(false)
{
	this->m_GraphType = GetGraphType(JSONObj["type"].get<std::string>());

	this->m_ID = JSONObj["id"].get<std::string>();
	this->m_Name = JSONObj["name"].get<std::string>();

	MATD_CORE_INFO("MATD::GRAPH MaterialGraph Loaded: {} {}", this->m_ID, this->m_Name);

	this->m_DataGraph = std::make_shared<MATD::GRAPH::DataGraph>(this, JSONObj["dataGraph"]);
	this->m_KernelGraph = std::make_shared<MATD::GRAPH::KernelGraph>(this, JSONObj["kernelGraph"]);
	this->m_ShaderGraph = std::make_shared<MATD::GRAPH::ShaderGraph>(this, JSONObj["shaderGraph"]);
}

MATD::GRAPH::MaterialGraph::MaterialGraph(MaterialProject* project, const MATD::JSON& JSONObj, bool isGraphNode) : m_Project(project), m_IsInitializedByGraph(isGraphNode)
{
	const auto data = JSONObj["data"];
	const auto graphType = data["type"].get<std::string>();
	this->m_GraphType = GetGraphType(graphType);

	this->m_ID = data["id"].get<std::string>();
	this->m_Name = data["name"].get<std::string>();

	MATD_CORE_INFO("MATD::GRAPH MaterialGraph inside MaterialGraphNode Loaded: {} {}", this->m_ID, this->m_Name);

	this->m_DataGraph = std::make_shared<MATD::GRAPH::DataGraph>(this, data["dataGraph"]);
	this->m_KernelGraph = std::make_shared<MATD::GRAPH::KernelGraph>(this, data["kernelGraph"]);
	this->m_ShaderGraph = std::make_shared<MATD::GRAPH::ShaderGraph>(this, data["shaderGraph"]);
}

MATD::GRAPH::MaterialGraph::~MaterialGraph()
{
}

MATD::Ref<MATD::GRAPH::Graph> MATD::GRAPH::MaterialGraph::GetGraph(GRAPH_TYPE graphType)
{
	switch (graphType)
	{
	case MATD::GRAPH::GRAPH_TYPE::DATA_GRAPH:
		return m_DataGraph;
	case MATD::GRAPH::GRAPH_TYPE::SHADER_GRAPH:
		return m_ShaderGraph;
	case MATD::GRAPH::GRAPH_TYPE::KERNEL_GRAPH:
		return m_KernelGraph;
	}

	MATD_CORE_ASSERT(false, "MATD::GRAPH Unknown graph type recieved");
	return m_DataGraph;
}

MATD::GRAPH::GRAPH_TYPE MATD::GRAPH::MaterialGraph::GetGraphType(const std::string& graphType)
{
	if (graphType == "dataGraph") {
		return GRAPH_TYPE::DATA_GRAPH;
	}
	else if (graphType == "shaderGraph") {
		return GRAPH_TYPE::SHADER_GRAPH;
	}
	else if (graphType == "kernelGraph") {
		return GRAPH_TYPE::KERNEL_GRAPH;
	}
	else {
		MATD_ASSERT(false, "MATD::GRAPH MaterialGraph unrecognized MaterialGraph type found!");
		return GRAPH_TYPE::DATA_GRAPH;
	}
}
