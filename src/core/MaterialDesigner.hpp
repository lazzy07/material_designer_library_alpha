#pragma once
#include "Core.hpp"
#include "EngineManager.hpp"
#include "../types/matd/Argument.hpp"

namespace MATD{
  namespace CORE{
    class MaterialDesigner{
      public:
        void SelectDevice(uint8_t platformId, uint8_t deviceId);
        void SetKenelLibraryFolder(const std::string& path);

        MATD::Int* CreateInt(int val);
        MATD::Float* CreateFloat(float val);
        MATD::Buffer* CreateBuffer(void* val, size_t size, size_t elem_size, buf_type argType=MATD::ARG_TYPE::DEVICE_READ);
				MATD::Image* CreateImage(void* val, size_t size, size_t elem_size, size_t width, size_t height, buf_type argType= MATD::ARG_TYPE::DEVICE_READ);
        MATD::WorkItem* CreateWorkItem(const std::string& kernelName);

        MaterialDesigner();
        ~MaterialDesigner();
    };
  };
}