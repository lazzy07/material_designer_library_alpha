#include "KernelGraph.hpp"
#include "../../core/MaterialDesigner.hpp"
#include "../core/MaterialGraph.hpp"
#include "../data_graph/DataNode.hpp"
#include "../../types/matd/Argument.hpp"

MATD::GRAPH::KernelGraph::KernelGraph(MATD::GRAPH::MaterialGraph* graph,const MATD::JSON& JSONObj) : MATD::GRAPH::Graph(graph, JSONObj)
{
	this->Init(JSONObj);
	MATD_CORE_TRACE("MATD::GRAPH KernelGraph created ID: {} MatGraphID: {}", this->GetID(), this->GetMaterialGraph()->GetID());
}

MATD::GRAPH::KernelGraph::~KernelGraph()
{
}


std::string MATD::GRAPH::KernelGraph::GetKernelName()
{
	std::string id = this->GetID();
	id.erase(std::remove(id.begin(), id.end(), '-'), id.end());
	return id;
}

std::string MATD::GRAPH::KernelGraph::IDToVariableName(std::string id) {
	id.erase(std::remove(id.begin(), id.end(), '-'), id.end());
	return id;
}

void MATD::GRAPH::KernelGraph::CreateNode(MATD::JSON JSONObj)
{
}

void MATD::GRAPH::KernelGraph::Update(MATD::JSON JSONObj)
{
	m_ShouldCompile = true;
	MATD_CORE_TRACE("Kernel update {}", JSONObj);
	std::string type = JSONObj["type"].get<std::string>();
	std::string update = JSONObj["update"].get<std::string>();

	if (type == "kernel") {
		m_KernelSource = update;
	}
	else if (type == "functions") {
		m_FunctionsSource = update;
	}
	else {
		MATD_CORE_ERROR("Unknown update type in Kernel: {}", this->GetID());
	}
}

void MATD::GRAPH::KernelGraph::Init(const MATD::JSON& JSONObj)
{
	this->SetID(JSONObj["id"].get<std::string>());
	m_KernelSource = JSONObj["data"]["kernel"].get<std::string>();
	m_KernelSource = JSONObj["data"]["functions"].get<std::string>();
}

std::string MATD::GRAPH::KernelGraph::Compile()
{
	InitKernel();
	std::string error;
	const auto kernel = MATD::Kernel::CreateKernelFromSource(this->GetKernelName(), m_ShaderSource, &error);
	m_EngineKernel.reset(kernel);
	m_WorkItem.reset(CORE::MaterialDesigner::CreateWorkItem(m_EngineKernel.get()));
	this->SetArgumentsToWorkItem();
	m_ShouldCompile = false;
	return error;
}

void MATD::GRAPH::KernelGraph::InitKernel()
{
	m_ShaderSource = "";
	std::string structs = R""""(
typedef float Number1;
typedef float ColorVec1;

struct ColorVec3 {
	float r;
	float g;
	float b;
};

struct Number2 {
	float x;
	float y;
};

struct Lut1Elem {
	ColorVec1 color;
	int pos;
};

struct Lut3Elem {
	struct ColorVec3 color;
	int pos;
};


)"""";

	m_ShaderSource += structs;
	m_ShaderSource += m_FunctionsSource;

	m_ShaderSource += "\n\n";

	m_ShaderSource += "__kernel void ";
	m_ShaderSource += ("kernel_" + this->GetKernelName() + "(") ;

	//add kernel parameters
	{
		auto materialGraph = this->GetMaterialGraph();
		auto shaderGraph = materialGraph->GetGraph(GRAPH_TYPE::SHADER_GRAPH);
		auto dataGraph = materialGraph->GetGraph(GRAPH_TYPE::DATA_GRAPH);

		//data parameters
		{
			auto dataOutputNodes = dataGraph->GetOutputNodes();
			

			size_t index = 0;
			std::string argList;
			for (const auto& node : dataOutputNodes) {
				auto outSocket = node->GetOutputSocket("out");
				auto arg = outSocket->GetArgument();


				auto argName = "_" + IDToVariableName(*node->GetFunction()->get()->GetArgument("var_name")->GetData<std::string>());
				
				argList += index > 0 ? "," : "";

				switch (arg->GetDataType())
				{
				case MATD::DATA_TYPES::NUMBER1:
					{
						index += 1;
						argList += "Number1 " + argName;
					}
					break;
				case MATD::DATA_TYPES::NUMBER2:
					{
						index += 1;
						argList += "struct Number2 " + argName;
					}
					break;
				case MATD::DATA_TYPES::STRING:
					break;
				case MATD::DATA_TYPES::BOOLEAN:
					{
						index += 1;
						argList += "int " + argName;
					}
					break;
				case MATD::DATA_TYPES::COLORVEC1:
					{
						index += 1;
						argList += "ColorVec1 " + argName;
					}
					break;
				case MATD::DATA_TYPES::COLORVEC3:
					{
						index += 1;
						argList += "struct ColorVec3 " + argName;
					}
					break;
				case MATD::DATA_TYPES::LUT1:
					{
						index += 2;
						argList += "struct Lut1Elem* " + argName;
						argList += ", int " + argName + "_size";
					}
					break;
				case MATD::DATA_TYPES::LUT3:
					{
						index += 2;
						argList += "struct Lut3Elem* " + argName;
						argList += ", int " + argName + "_size";
					}
					break;
				}
			}

			for(auto [fst, node]: *shaderGraph->GetNodes())
			{
				if(node->GetName() == "KernelInput")
				{
					auto argName = "_" + IDToVariableName(*node->GetFunction()->get()->GetArgument("var_name")->GetData<std::string>());

					argList += index > 0 ? "," : "";
					argList += "__read_only  image2d_t " + argName;
					index += 1;
				}
			}

			m_ShaderSource += argList + "){\n\n";
			m_ShaderSource += m_KernelSource;
			m_ShaderSource += "\n\n};";
		}
	}

	MATD_CORE_TRACE("Kernel: \n" + m_ShaderSource);
}

void MATD::GRAPH::KernelGraph::SetArgumentsToWorkItem()
{
	auto materialGraph = this->GetMaterialGraph();
	auto shaderGraph = materialGraph->GetGraph(GRAPH_TYPE::SHADER_GRAPH);
	auto dataGraph = materialGraph->GetGraph(GRAPH_TYPE::DATA_GRAPH);

	auto dataOutputNodes = dataGraph->GetOutputNodes();
	size_t index = 0;
	

	for (const auto& node : dataOutputNodes) {
		auto outSocket = node->GetOutputSocket("out");
		auto arg = outSocket->GetArgument();

		switch (arg->GetDataType())
		{
		case MATD::DATA_TYPES::NUMBER1:
		{
			auto* val = (DTYPES::Argument*)MATD::Argument::Int(*arg->GetData<Number1>());
			m_WorkItem->SetArgument(index, val);
			index += 1;
		}
		break;
		case MATD::DATA_TYPES::NUMBER2:
		{
			auto* val = (DTYPES::Argument*)MATD::Argument::Number2(*arg->GetData<Number2>());
			m_WorkItem->SetArgument(index, val);
			index += 1;
		}
		break;
		case MATD::DATA_TYPES::STRING:
			break;
		case MATD::DATA_TYPES::BOOLEAN:
		{
			auto* val = (DTYPES::Argument*)MATD::Argument::Int(*arg->GetData<bool>());
			m_WorkItem->SetArgument(index, val);
			index += 1;
		}
		break;
		case MATD::DATA_TYPES::COLORVEC1:
		{
			auto* val = (DTYPES::Argument*)MATD::Argument::Int(*arg->GetData<ColorVec1>());
			m_WorkItem->SetArgument(index, val);
			index += 1;
		}
		break;
		case MATD::DATA_TYPES::COLORVEC3:
		{
			auto* val = (DTYPES::Argument*)MATD::Argument::ColorVec3(*arg->GetData<ColorVec3>());
			m_WorkItem->SetArgument(index, val);
			index += 1;
		}
		break;
		case MATD::DATA_TYPES::LUT1:
		{
			auto data = arg->GetData<Lut1>();
			auto* val = (DTYPES::Argument*)MATD::Argument::Buffer(data->stops, data->length, sizeof(Lut1Elem), ARG_TYPE::DEVICE_READ);
			m_WorkItem->SetArgument(index, val);
			m_WorkItem->SetArgument(index + 1, (DTYPES::Argument*)MATD::Argument::Int(*arg->GetData<Number1>()));
			index += 2;
		}
		break;
		case MATD::DATA_TYPES::LUT3:
		{
			auto data = arg->GetData<Lut3>();
			auto* val = (DTYPES::Argument*)MATD::Argument::Buffer(data->stops, data->length, sizeof(Lut3Elem), ARG_TYPE::DEVICE_READ);
			m_WorkItem->SetArgument(index, val);
			m_WorkItem->SetArgument(index + 1, (DTYPES::Argument*)MATD::Argument::Int(*arg->GetData<Number1>()));
			index += 2;
		}
		break;
		}
	}
}

void MATD::GRAPH::KernelGraph::SetOutputs()
{
}

void MATD::GRAPH::KernelGraph::SubmitToQueue(Ref<MATD::Queue> queue)
{
}

