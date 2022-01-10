#pragma once
#include "../../core/Core.hpp"
#include "../data_graph/DataGraph.hpp"
#include "../shader_graph/ShaderGraph.hpp"
#include "../kernel_graph/KernelGraph.hpp"
#include "../data_graph/DataCache.hpp"
#include "../shader_graph/ShaderCache.hpp"

namespace MATD{
  namespace GRAPH{
    enum class GRAPH_TYPE {
      DATA_GRAPH,
      SHADER_GRAPH,
      KERNEL_GRAPH
    };

    class MaterialProject;

    class MaterialGraph{
    public:
      static GRAPH_TYPE GetGraphType(const std::string& graphType);

      MaterialGraph(MaterialProject* project, const MATD::JSON& JSONObj);
      ~MaterialGraph();

      inline const std::string& GetID() { return m_ID; };
      Ref<MATD::GRAPH::Graph> GetGraph(GRAPH_TYPE graphType);

    private:
      std::string m_ID;
      std::string m_Name;
      MaterialProject* m_Project;

      GRAPH_TYPE m_GraphType;

      Ref<DataGraph> m_DataGraph;
      Ref<ShaderGraph> m_ShaderGraph;
      Ref<KernelGraph> m_KernelGraph;

			Ref<ShaderCache> m_ShaderCache;
			Ref<DataCache> m_DataCache;
    };
  }
}