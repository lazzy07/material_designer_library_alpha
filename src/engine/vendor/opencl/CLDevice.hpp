#pragma once
#include <CL/cl.hpp>
#include "../../matd/Device.hpp"
#include "../../../core/Core.hpp"
#include "CLContext.hpp"

namespace MATD{
  namespace ENGINE{
    namespace OPENCL{
      class Device : public ENGINE::Device{
      public:
        Device(std::string deviceName, MATD::ENGINE::MAT_DEVICE_TYPE type);
        void SetCLDeviceData(cl::Device device, cl_uint maxUnits, cl_uint maxDim, std::vector<size_t> maxItem, cl_uint grpSize);
        void InitDevice();
        inline const Ref<OPENCL::Context> GetContext() const { return m_Context; };
        inline cl::Device GetClDevice() const { return m_Device; };

        virtual void EnqueueWorkItem(Ref<ENGINE::WorkItem> workItem) override;
      private:
        cl::Device m_Device;
        cl::CommandQueue m_Queue;
        cl_uint m_DeviceMaxComputeUnits = 0;
        cl_uint m_DeviceMaxWorkItemDimensions = 0;
        std::vector<size_t> m_DeviceMaxWorkItemSizes;
        cl_uint m_DeviceMaxGroupSize = 0;
        Ref<OPENCL::Context> m_Context;
      };
    };
  };
};