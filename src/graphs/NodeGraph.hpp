#pragma once
#include "../core/Core.hpp"
#include "DataGraph.hpp"
#include "ShaderGraph.hpp"
#include "KernelGraph.hpp"

namespace MATD{
  namespace GRAPH{
    enum class GRAPH_TYPE {
      DATA_GRAPH,
      SHADER_GRAPH,
      KERNEL_GRAPH
    };

    class NodeGraph{
    public:
      NodeGraph(const MATD::JSON& JSONObj);
      ~NodeGraph();

    private:
      std::string m_ID;
      std::string m_Name;

      GRAPH_TYPE m_GraphType;

      Ref<DataGraph> m_DataGraph;
      Ref<ShaderGraph> m_ShaderGraph;
      Ref<KernelGraph> m_KernelGraph;

    private:
      GRAPH_TYPE SetGraphType(const std::string& graphType);
    };
  }
}