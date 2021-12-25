#pragma once
#include "NodeGraph.hpp"

namespace MATD{
  namespace GRAPH{
    class NodeProject{
      public:
        void OpenProject(const std::string& JSONString);
        void UpdateProject(const std::string& JSONString);
				void SetSelectedGraph(const std::string& graphID);
				void UpdateGraph(const std::string& JSONString);
      private:
        Ref<NodeGraph> m_SelectedNodeGraph;
        std::map<std::string, Ref<NodeGraph>> m_Graphs;
    };
  }
}