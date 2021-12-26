#include "NodeGraph.hpp"

MATD::GRAPH::NodeGraph::NodeGraph(const MATD::JSON& JSONObj)
{
	this->m_GraphType = SetGraphType(JSONObj["type"].get<std::string>());

	this->m_ID = JSONObj["id"].get<std::string>();
	this->m_Name = JSONObj["name"].get<std::string>();

	MATD_CORE_INFO("MATD::GRAPH NodeGraph Loaded: {} {}", this->m_ID, this->m_Name);

	this->m_DataGraph = std::make_shared<MATD::GRAPH::DataGraph>(JSONObj["dataGraph"]);
	this->m_KernelGraph = std::make_shared<MATD::GRAPH::KernelGraph>(JSONObj["kernelGraph"]);
	this->m_ShaderGraph = std::make_shared<MATD::GRAPH::ShaderGraph>(JSONObj["shaderGraph"]);
}

MATD::GRAPH::NodeGraph::~NodeGraph()
{
}

MATD::GRAPH::GRAPH_TYPE MATD::GRAPH::NodeGraph::SetGraphType(const std::string& graphType)
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
		MATD_ASSERT(false, "MATD::GRAPH NodeGraph unrecognize nodegraph type found!");
		return GRAPH_TYPE::DATA_GRAPH;
	}
}
