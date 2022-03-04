#pragma once
#include "Core.hpp"
#include "EngineManager.hpp"
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
        void SetKenelLibraryFolder(const std::string& path);

        MATD::Int* CreateInt(int val);
        MATD::Float* CreateFloat(float val);
        MATD::Buffer* CreateBuffer(void* val, size_t size, size_t elem_size, buf_type argType=MATD::ARG_TYPE::DEVICE_READ);
	      MATD::Image* CreateImage(void* val, size_t size, size_t elem_size, size_t width, size_t height, buf_type argType= MATD::ARG_TYPE::DEVICE_READ);
        MATD::WorkItem* CreateWorkItem(const std::string& kernelName);
        MATD::Queue* CreateQueue();

        void OpenProject(const std::string& JSONString);
        void UpdateProject(const std::string& JSONString);

        void SetSelectedGraph(const std::string& graphID);

				void CreateNode(const std::string& JSONString);
				void RemoveNode(const std::string& JSONString);
				void AddConnection(const std::string& JSONString);
				void RemoveConnection(const std::string& JSONString);
				void Update(const std::string& JSONString);
        std::string CompileKernel();

        inline void SetUsedByMaterialDesignerApp(bool isUsedByApp) { this->m_IsUsedByMaterialDesignerApp = isUsedByApp; };
        inline bool GetUsedByMaterialDesignerApp() { return m_IsUsedByMaterialDesignerApp; };

        inline const Ref<MATD::GRAPH::MaterialProject> GetNodeProject() { return m_CurrentProject; };
    private:
        Ref<MATD::CORE::KernelLibrary> m_KernelLibrary;
        Ref<MATD::GRAPH::MaterialProject> m_CurrentProject;
        bool m_IsUsedByMaterialDesignerApp = false;
    };
  };
}