#include "MaterialProject.hpp"

MATD::GRAPH::MaterialProject::MaterialProject()
{
	MATD_CORE_TRACE("MATD::GRAPH:: A new project created");
	this->m_JSONParser = std::make_shared<MATD::CORE::JSONParser>();

	this->m_DataCache = std::make_shared<MATD::GRAPH::DataCache>();
	this->m_ShaderCache = std::make_shared<MATD::GRAPH::ShaderCache>();
}

MATD::GRAPH::MaterialProject::~MaterialProject()
{
}

void MATD::GRAPH::MaterialProject::OpenProject(const std::string& JSONString)
{
	MATD::JSON projectJSON = m_JSONParser->ParseJSON(JSONString);

	this->m_ProjectID = projectJSON["id"].get<std::string>();
	this->m_FileName = projectJSON["fileName"].get<std::string>();
	this->m_IsLocal = projectJSON["isLocal"].get<bool>();

	MATD::JSON packages = projectJSON["packages"];

	for (MATD::JSON::iterator it = packages.begin(); it != packages.end(); it++) {
		this->ParsePackages(it.value());
	}
}

void MATD::GRAPH::MaterialProject::UpdateProject(const std::string& JSONString)
{
	MATD::JSON projectJSON = m_JSONParser->ParseJSON(JSONString);

	this->m_ProjectID = projectJSON["id"].get<std::string>();
	this->m_FileName = projectJSON["fileName"].get<std::string>();
	this->m_IsLocal = projectJSON["isLocal"].get<bool>();

	MATD::JSON packages = projectJSON["packages"];

	for (MATD::JSON::iterator it = packages.begin(); it != packages.end(); it++) {
		this->ParsePackages(it.value());
	}
}

void MATD::GRAPH::MaterialProject::SetSelectedGraph(const std::string& data)
{
	MATD::JSON json = m_JSONParser->ParseJSON(data);
	
	std::string graphID = json["id"].get<std::string>();
	std::string graphType = json["type"].get<std::string>();

	m_SelectedGraphType = MATD::GRAPH::MaterialGraph::GetGraphType(graphType);

	auto selectedGraph = m_Graphs.find(graphID);

	if (selectedGraph == m_Graphs.end()) {
		MATD_CORE_ASSERT(false, "MATD::GRAPH:: Unknown graphID found");
	}
	else {
		this->m_SelectedMaterialGraph = selectedGraph->second;
		MATD_CORE_TRACE("MATD::GRAPH:: Selected MaterialGraph Change, Graph ID: {} Type: {}", m_SelectedMaterialGraph->GetID(), graphType);
	}
}

void MATD::GRAPH::MaterialProject::UpdateGraph(const std::string& JSONString)
{
	MATD::JSON update = m_JSONParser->ParseJSON(JSONString);
	auto selectedGraph = this->m_SelectedMaterialGraph;

	Ref<Graph> graph = m_SelectedMaterialGraph->GetGraph(m_SelectedGraphType);
	graph->Update(update);
}

void MATD::GRAPH::MaterialProject::ParsePackages(MATD::JSON package)
{
	if (package["contentType"] == "package") {
		auto children = package["children"];
		for (MATD::JSON::iterator it = children.begin(); it != children.end(); it++) {
			this->ParsePackages(it.value());
		}
	}
	else {
		if (this->m_Graphs.find(package["id"]) == this->m_Graphs.end()) {
			Ref<MATD::GRAPH::MaterialGraph> graph = std::make_shared<MATD::GRAPH::MaterialGraph>(this, package);
			this->m_Graphs.insert(std::pair<std::string, Ref<MATD::GRAPH::MaterialGraph>>(package["id"].get<std::string>(), graph));
		}
	}
}
	