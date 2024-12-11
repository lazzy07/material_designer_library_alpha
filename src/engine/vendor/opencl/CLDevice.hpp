#pragma once
#include <CL/cl.hpp>
#include "../../matd/Device.hpp"
#include "../../../core/Core.hpp"
#include "CLContext.hpp"

namespace MATD{
  namespace ENGINE{
    namespace OPENCL{
      /**
       * @brief Device class for OpenCL, used to store the device information and context
       * 
       */
      class Device : public ENGINE::Device{
      public:
        Device(std::string deviceName, MATD::ENGINE::MAT_DEVICE_TYPE type);
        void SetCLDeviceData(cl::Device device, cl_uint maxUnits, cl_uint maxDim, std::vector<size_t> maxItem, cl_uint grpSize);
        void InitDevice();
        inline Ref<OPENCL::Context> GetContext() const { return m_Context; };
				inline cl::Device GetClDevice() const { return m_Device; };

      private:
        cl::Device m_Device;
        cl_uint m_DeviceMaxComputeUnits = 0;
        cl_uint m_DeviceMaxWorkItemDimensions = 0;
        std::vector<size_t> m_DeviceMaxWorkItemSizes;
        cl_uint m_DeviceMaxGroupSize = 0;
        Ref<OPENCL::Context> m_Context;
      };
    };
  };
};