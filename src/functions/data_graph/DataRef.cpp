#include "DataRef.hpp"

#include "../../graphs/core/Graph.hpp"
#include "../../graphs/core/Node.hpp"
#include "../../graphs/core/MaterialGraph.hpp"
#include "../../graphs/core/MaterialProject.hpp"
#include "../../functions/shader_graph/ShaderGraphNode.hpp"

MATD::FUNC::DATA::OUTPUT::DataRef::DataRef(MATD::GRAPH::Node* node) : DataPrimitiveFunction(node)
{
}

void MATD::FUNC::DATA::OUTPUT::DataRef::Init(MATD::JSON JSONObj)
{
	const auto data = JSONObj["data"];
	const auto graphId = data["graphId"].get<std::string>();
	const auto nodeId = data["nodeId"].get<size_t>();
	const auto subNodeId = data["subnodeId"].get<size_t>();
	const auto project = this->GetNode()->GetGraph()->GetMaterialGraph()->GetProject();
	const auto matGraph = project->GetGraph(graphId);
	const auto shaderGraph = matGraph->GetGraph(GRAPH::GRAPH_TYPE::SHADER_GRAPH);
	const auto shaderGraphNode = shaderGraph->GetNode(nodeId).get();

	//Now we have the reference to the shader graph node
	if(const auto shaderGraphFunc = dynamic_cast<SHADER::PROCESS::ShaderGraphNode*>(shaderGraphNode->GetFunction()->get()))
	{
		const auto matGraphRef = shaderGraphFunc->GetMaterialGraph();
		const auto dataGraphRef = matGraphRef->GetGraph(GRAPH::GRAPH_TYPE::DATA_GRAPH);

		if(const auto nodeRef = dataGraphRef->GetNode(subNodeId))
		{
			auto socket = nodeRef->GetInputSocket("1");
			this->GetNode()->AddInputSocket("1", socket);
		}
	}
}

void MATD::FUNC::DATA::OUTPUT::DataRef::Calculate()
{

}

void MATD::FUNC::DATA::OUTPUT::DataRef::SetSocketArguments()
{

}
