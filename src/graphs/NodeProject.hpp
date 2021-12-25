#pragma once
#include "NodeGraph.hpp"
#include "../core/Core.hpp"
#include "../core/JSONParser.hpp"
#include <map>
#include <string>

namespace MATD{
  namespace GRAPH{
    class NodeProject{
      public:
        void OpenProject(const std::string& JSONString);
        void UpdateProject(const std::string& JSONString);
				void SetSelectedGraph(const std::string& graphID);
				void UpdateGraph(const std::string& JSONString);
      private:
        std::string m_ProjectID;
        std::string m_FileName;
        bool m_IsLocal;
        
        Ref<NodeGraph> m_SelectedNodeGraph;
        std::map<std::string, Ref<NodeGraph>> m_Graphs;

      private:
        void ParsePackages(MATD::JSON json);
    };
  }
}