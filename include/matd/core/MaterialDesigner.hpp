#pragma once
#include "Core.hpp"
#include "EngineManager.hpp"
#include "../types/DataTypes.hpp"
#include "KernelLibrary.hpp"
#include "../graphs/MaterialProject.hpp"

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
        void UpdateGraph(const std::string& JSONString);

        inline const Ref<MATD::GRAPH::MaterialProject> GetNodeProject() { return m_CurrentProject; };
    private:
        Ref<MATD::CORE::KernelLibrary> m_KernelLibrary;
        Ref<MATD::GRAPH::MaterialProject> m_CurrentProject;
    };
  }
}