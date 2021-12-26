#include "NodeProject.hpp"

void MATD::GRAPH::NodeProject::OpenProject(const std::string& JSONString)
{
	MATD::CORE::JSONParser* jp = new MATD::CORE::JSONParser(JSONString);
	MATD::JSON projectJSON = jp->GetMap();

	this->m_ProjectID = projectJSON["id"].get<std::string>();
	this->m_FileName = projectJSON["fileName"].get<std::string>();
	this->m_IsLocal = projectJSON["isLocal"].get<bool>();

	MATD::JSON packages = projectJSON["packages"];

	for (MATD::JSON::iterator it = packages.begin(); it != packages.end(); it++) {
		this->ParsePackages(it.value());
	}

	delete jp;
}

void MATD::GRAPH::NodeProject::UpdateProject(const std::string& JSONString)
{
	MATD::CORE::JSONParser* jp = new MATD::CORE::JSONParser(JSONString);
	MATD::JSON projectJSON = jp->GetMap();

	this->m_ProjectID = projectJSON["id"].get<std::string>();
	this->m_FileName = projectJSON["fileName"].get<std::string>();
	this->m_IsLocal = projectJSON["isLocal"].get<bool>();

	MATD::JSON packages = projectJSON["packages"];

	for (MATD::JSON::iterator it = packages.begin(); it != packages.end(); it++) {
		this->ParsePackages(it.value());
	}

	delete jp;
}

void MATD::GRAPH::NodeProject::SetSelectedGraph(const std::string& graphID)
{
}

void MATD::GRAPH::NodeProject::UpdateGraph(const std::string& JSONString)
{
}

void MATD::GRAPH::NodeProject::ParsePackages(MATD::JSON package)
{
	if (package["contentType"] == "package") {
		auto children = package["children"];
		for (MATD::JSON::iterator it = children.begin(); it != children.end(); it++) {
			this->ParsePackages(it.value());
		}
	}
	else {
		if (this->m_Graphs.find(package["id"]) == this->m_Graphs.end()) {
			Ref<MATD::GRAPH::NodeGraph> graph = std::make_shared<MATD::GRAPH::NodeGraph>(package);
			this->m_Graphs.insert(std::pair<std::string, Ref<MATD::GRAPH::NodeGraph>>(package["id"].get<std::string>(), graph));
		}
	}
}
	