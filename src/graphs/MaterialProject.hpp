#pragma once
#include "MaterialGraph.hpp"
#include "../core/Core.hpp"
#include "../core/JSONParser.hpp"
#include "ShaderCache.hpp"
#include "DataCache.hpp"
#include <map>
#include <string>

namespace MATD{
  namespace GRAPH{
    class MaterialProject{
      public:
        MaterialProject();
        ~MaterialProject();

        void OpenProject(const std::string& JSONString);
        void UpdateProject(const std::string& JSONString);
				void SetSelectedGraph(const std::string& graphID);
				void UpdateGraph(const std::string& JSONString);
      private:
        std::string m_ProjectID;
        std::string m_FileName;
        bool m_IsLocal;
        
        Ref<MaterialGraph> m_SelectedMaterialGraph;
        Ref<ShaderCache> m_ShaderCache;
        Ref<DataCache> m_DataCache;

        std::map<std::string, Ref<MaterialGraph>> m_Graphs;
      private:
        void ParsePackages(MATD::JSON json);
    };
  }
}