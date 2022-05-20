#include "MaterialProject.hpp"
#include "../../types/matd/Argument.hpp"
MATD::GRAPH::MaterialProject::MaterialProject() : m_GlobalBitDepth(MATD_TEXTURE_BIT_TYPE::TEX_8BIT), m_GlobalTexHeight(1024), m_GlobalTexWidth(1024), m_IsLocal(true)
{
	MATD_CORE_INFO("MATD::GRAPH:: A new project created");
	this->m_JSONParser = std::make_shared<MATD::CORE::JSONParser>();
	this->m_Queue.reset(MATD::Queue::CreateQueue());
	this->m_DefaultTextureGrayscale.reset(Argument::GrayscaleTexture(m_GlobalBitDepth, m_GlobalTexWidth, m_GlobalTexHeight, MATD::ARG_TYPE::DEVICE_READ));
	this->m_DefaultTextureColor.reset(Argument::ColorTexture(m_GlobalBitDepth, m_GlobalTexWidth, m_GlobalTexHeight, MATD::ARG_TYPE::DEVICE_READ));
}

MATD::GRAPH::MaterialProject::~MaterialProject()
{
	MATD_CORE_TRACE("MATD::PROJECT Project Deleted");
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

	auto selectedGraph = m_Graphs.find(graphID);

	if (selectedGraph == m_Graphs.end()) {
		MATD_CORE_ASSERT(false, "MATD::GRAPH:: Unknown graphID found");
	}
	else {
		this->m_SelectedMaterialGraph = selectedGraph->second;
		MATD_CORE_INFO("MATD::GRAPH:: Selected MaterialGraph Changed, Graph ID: {} Type: {}", m_SelectedMaterialGraph->GetID());
	}
}

void MATD::GRAPH::MaterialProject::CreateNode(const std::string& selectedGraphType, const std::string& JSONString)
{
	const MATD::JSON update = m_JSONParser->ParseJSON(JSONString);
	auto selectedGraph = this->m_SelectedMaterialGraph;
	auto graphType = MaterialGraph::GetGraphType(selectedGraphType);
	Ref<Graph> graph = m_SelectedMaterialGraph->GetGraph(graphType);
	graph->CreateNode(update);
}

void MATD::GRAPH::MaterialProject::RemoveNode(const std::string& selectedGraphType, const std::string& JSONString)
{
	const MATD::JSON update = m_JSONParser->ParseJSON(JSONString);
	auto graphType = MaterialGraph::GetGraphType(selectedGraphType);
	Ref<Graph> graph = m_SelectedMaterialGraph->GetGraph(graphType);
	graph->RemoveNode(update);
}

void MATD::GRAPH::MaterialProject::AddConnection(const std::string& selectedGraphType, const std::string& JSONString)
{
	const MATD::JSON update = m_JSONParser->ParseJSON(JSONString);
	auto graphType = MaterialGraph::GetGraphType(selectedGraphType);
	Ref<Graph> graph = m_SelectedMaterialGraph->GetGraph(graphType);
	graph->AddConnection(update);
}

void MATD::GRAPH::MaterialProject::RemoveConnection(const std::string& selectedGraphType, const std::string& JSONString)
{
	const MATD::JSON update = m_JSONParser->ParseJSON(JSONString);
	auto selectedGraph = this->m_SelectedMaterialGraph;
	auto graphType = MaterialGraph::GetGraphType(selectedGraphType);
	Ref<Graph> graph = m_SelectedMaterialGraph->GetGraph(graphType);
	graph->RemoveConnection(update);
}

void MATD::GRAPH::MaterialProject::Update(const std::string& selectedGraphType, const std::string& JSONString)
{
	const MATD::JSON update = m_JSONParser->ParseJSON(JSONString);
	auto graphType = MaterialGraph::GetGraphType(selectedGraphType);
	Ref<Graph> graph = m_SelectedMaterialGraph->GetGraph(graphType);
	graph->Update(update);
}

std::string MATD::GRAPH::MaterialProject::CompileKernel()
{
	if (m_SelectedMaterialGraph->GetType() == GRAPH_TYPE::KERNEL_GRAPH) {
		const auto graph = m_SelectedMaterialGraph->GetGraph(GRAPH_TYPE::KERNEL_GRAPH);
		const auto kernelGraph = (MATD::GRAPH::KernelGraph*)graph.get();

		return kernelGraph->Compile();
	}
	else {
		MATD_CORE_WARN("MATD::GRAPHS Warning::Selected graph is not a Kernel Graph");
		return "";
	}
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
			this->m_Graphs.insert(std::pair(package["id"].get<std::string>(), graph));
		}
	}
}
	