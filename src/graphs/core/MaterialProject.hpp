#pragma once
#include "MaterialGraph.hpp"
#include "../../core/Core.hpp"
#include "../../core/JSONParser.hpp"
#include "../shader_graph/ShaderCache.hpp"
#include "../data_graph/DataCache.hpp"
#include "../../types/matd/Texture.hpp"
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

				void CreateNode(const std::string& JSONString);
				void RemoveNode(const std::string& JSONString);
				void AddConnection(const std::string& JSONString);
				void RemoveConnection(const std::string& JSONString);
				void Update(const std::string& JSONString);
        std::string CompileKernel();
      private:
        std::string m_ProjectID;
        std::string m_FileName;
        bool m_IsLocal;
        
        Ref<MaterialGraph> m_SelectedMaterialGraph;
        MATD::GRAPH::GRAPH_TYPE m_SelectedGraphType;

        std::map<std::string, Ref<MaterialGraph>> m_Graphs;
        Ref<MATD::CORE::JSONParser> m_JSONParser;

        MATD::MATD_TEXTURE_BIT_TYPE m_GlobalBitDepth;
				size_t m_GlobalTexHeight;
				size_t m_GlobalTexWidth;
      private:
        void ParsePackages(MATD::JSON json);
    };
  }
}