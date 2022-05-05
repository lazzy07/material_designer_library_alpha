#pragma once
#include "Core.hpp"
#include "KernelLibrary.hpp"
#include "../types/matd/Argument.hpp"
#include "../engine/matd/Queue.hpp"
#include "../graphs/core/MaterialProject.hpp"
#include <map>

namespace MATD{

  namespace CORE{
    class MaterialDesigner{
      public:
    		MaterialDesigner();
        ~MaterialDesigner();
        
    		void SelectDevice(uint8_t platformId, uint8_t deviceId);
    		void SetKernelLibraryFolder(const std::string& path);

    		static MATD::Int* CreateInt(int val);
    		static MATD::Float* CreateFloat(float val);
    		static MATD::Buffer* CreateBuffer(void* val, size_t size, size_t elem_size, buf_type argType=MATD::ARG_TYPE::DEVICE_READ);
    		static MATD::GrayscaleTexture* CreateGrayscaleTexture(MATD_TEXTURE_BIT_TYPE bitType, size_t width, size_t height, buf_type argType = MATD::ARG_TYPE::DEVICE_READ);
    		static MATD::ColorTexture* CreateColorTexture(MATD_TEXTURE_BIT_TYPE bitType, size_t width, size_t height, buf_type argType = MATD::ARG_TYPE::DEVICE_READ);
    		static MATD::WorkItem* CreateWorkItem(MATD::Kernel* kernel);
    		static MATD::Queue* CreateQueue();

    		void OpenProject(const std::string& JSONString);
    		void UpdateProject(const std::string& JSONString);

    		void SetSelectedGraph(const std::string& graphID);

				void CreateNode(const std::string& JSONString);
				void RemoveNode(const std::string& JSONString);
				void AddConnection(const std::string& JSONString);
				void RemoveConnection(const std::string& JSONString);
				void Update(const std::string& JSONString);
    		std::string CompileKernel();

    		static void SetUsedByMaterialDesignerApp(bool isUsedByApp) { m_IsUsedByMaterialDesignerApp = isUsedByApp; };
    		static bool GetUsedByMaterialDesignerApp() { return m_IsUsedByMaterialDesignerApp; };

        [[nodiscard]] Ref<MATD::GRAPH::MaterialProject> GetNodeProject() const;

    		static [[nodiscard]] Ref<DTYPES::Texture> GetOutputTexture() { return m_OutputTexture; }
    		static void SetOutputTexture(const Ref<MATD::DTYPES::Texture>& texture) { m_OutputTexture = texture; }

    		static [[nodiscard]] GRAPH::Node* GetOutputNode() { return m_OutputNode; }
    		static void SetOutputNode(GRAPH::Node* node) { m_OutputNode = node; }
    private:
    	Ref<MATD::CORE::KernelLibrary> m_KernelLibrary;
    	Ref<MATD::GRAPH::MaterialProject> m_CurrentProject;
    	inline static bool m_IsUsedByMaterialDesignerApp = false;

    	inline static Ref<MATD::DTYPES::Texture> m_OutputTexture;
    	inline static MATD::GRAPH::Node* m_OutputNode;
    };
  };
}