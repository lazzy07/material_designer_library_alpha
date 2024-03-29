#pragma once
#include "MaterialGraph.hpp"
#include "../../core/Core.hpp"
#include "../../core/JSONParser.hpp"
#include "../../types/matd/Texture.hpp"
#include "../../types/matd/GrayscaleTexture.hpp"
#include "../../types/matd/ColorTexture.hpp"
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
				void SetSelectedGraph(const std::string& data);

				void CreateNode(const std::string& selectedGraphType, const std::string& JSONString);
				void RemoveNode(const std::string& selectedGraphType, const std::string& JSONString);
				void AddConnection(const std::string& selectedGraphType, const std::string& JSONString);
				void RemoveConnection(const std::string& selectedGraphType, const std::string& JSONString);
				void Update(const std::string& selectedGraphType, const std::string& JSONString);
        std::string CompileKernel();

        Ref<MATD::GrayscaleTexture> GetDefaultGrayscaleTexture() { return m_DefaultTextureGrayscale; }
        Ref<MATD::ColorTexture> GetDefaultColorTexture() { return m_DefaultTextureColor; }

        size_t GetGlobalTexWidth() const { return m_GlobalTexWidth; }
        size_t GetGlobalTexHeight() const { return m_GlobalTexHeight; }
        [[nodiscard]] MATD::MATD_TEXTURE_BIT_TYPE GetGlobalBitDepth() const { return m_GlobalBitDepth; }
        [[nodiscard]] Ref<Queue> GetQueue() const { return m_Queue; }
        [[nodiscard]] Ref<MaterialGraph> GetGraph(const std::string& graphId) { return m_Graphs[graphId]; }
      private:
        std::string m_ProjectID;
        std::string m_FileName;
        bool m_IsLocal;
        
        Ref<MaterialGraph> m_SelectedMaterialGraph;

        std::map<std::string, Ref<MaterialGraph>> m_Graphs;
        Ref<MATD::CORE::JSONParser> m_JSONParser;

        MATD::MATD_TEXTURE_BIT_TYPE m_GlobalBitDepth;
				size_t m_GlobalTexHeight;
				size_t m_GlobalTexWidth;
        Ref<MATD::GrayscaleTexture> m_DefaultTextureGrayscale;
        Ref<MATD::ColorTexture> m_DefaultTextureColor;

        Ref<MATD::Queue> m_Queue;
      private:
        void ParsePackages(MATD::JSON package);
    };
  }
}