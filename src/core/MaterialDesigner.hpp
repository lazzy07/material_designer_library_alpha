#pragma once
#include "Core.hpp"
#include "KernelLibrary.hpp"
#include "../types/matd/Argument.hpp"
#include "../engine/matd/Queue.hpp"
#include "../graphs/core/MaterialProject.hpp"

namespace MATD{
  namespace CORE{
    class MaterialDesigner{
      public:
    		MaterialDesigner();
        ~MaterialDesigner();
        
    		void SelectDevice(uint8_t platformId, uint8_t deviceId);
    		void SetKernelLibraryFolder(const std::string& path) const;

        static MATD::Int* CreateInt(int val);
    		static MATD::Float* CreateFloat(float val);
    		static MATD::Buffer* CreateBuffer(void* val, size_t size, size_t elem_size, buf_type argType=MATD::ARG_TYPE::DEVICE_READ);
    		static MATD::GrayscaleTexture* CreateGrayscaleTexture(MATD_TEXTURE_BIT_TYPE bitType, size_t width, size_t height, buf_type argType = MATD::ARG_TYPE::DEVICE_READ);
    		static MATD::ColorTexture* CreateColorTexture(MATD_TEXTURE_BIT_TYPE bitType, size_t width, size_t height, buf_type argType = MATD::ARG_TYPE::DEVICE_READ);
    		static MATD::WorkItem* CreateWorkItem(MATD::Kernel* kernel);
    		static MATD::Queue* CreateQueue();

    		void OpenProject(const std::string& JSONString);
    		void UpdateProject(const std::string& JSONString) const;

    		void SetSelectedGraph(const std::string& graphID) const;

				void CreateNode(const std::string& JSONString) const;
				void RemoveNode(const std::string& JSONString) const;
				void AddConnection(const std::string& JSONString) const;
				void RemoveConnection(const std::string& JSONString) const;
				void Update(const std::string& JSONString) const;
        [[nodiscard]] std::string CompileKernel() const;

    		static void SetUsedByMaterialDesignerApp(bool isUsedByApp) { m_IsUsedByMaterialDesignerApp = isUsedByApp; };
    		static bool GetUsedByMaterialDesignerApp() { return m_IsUsedByMaterialDesignerApp; };

        [[nodiscard]] Ref<MATD::GRAPH::MaterialProject> GetNodeProject() const;

        static void UpdateShaderNodeData(int nodeId, MATD::DTYPES::Texture* texture);
        static void SetCallShaderNodeChangeCallback(void(*func)(int, MATD::DTYPES::Texture*)) { m_CallShaderNodeChangeCallback = func; }
        static void CallShaderNodeChangeCallback(int nodeId, MATD::DTYPES::Texture* texture) { m_CallShaderNodeChangeCallback(nodeId, texture); }
    private:
    	Ref<MATD::CORE::KernelLibrary> m_KernelLibrary;
    	Ref<MATD::GRAPH::MaterialProject> m_CurrentProject;
    	inline static bool m_IsUsedByMaterialDesignerApp = false;
      inline static void(*m_CallShaderNodeChangeCallback)(int, MATD::DTYPES::Texture*);
    };
  };
}
