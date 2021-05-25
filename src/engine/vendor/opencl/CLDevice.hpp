#pragma once
#include "../../matd/Device.hpp"
#include <CL/opencl.h>
namespace MATD{
  namespace ENGINE{
    namespace OPENCL{
      class Device : public ENGINE::Device{
      public:
        Device(std::string deviceName, DEVICE_TYPE type);
        void SetCLDeviceData(cl_device_id id, cl_uint maxUnits, cl_uint maxDim, cl_uint maxItem, cl_uint grpSize);

      private:
        cl_device_id m_DeviceId;
        cl_uint m_DeviceMaxComputeUnits = 0;
        cl_uint m_DeviceMaxWorkItemDimensions = 0;
        cl_uint m_DeviceMaxWorkItemSizes = 0;
        cl_uint m_DeviceMaxGroupSize = 0;
      };
    };
  };
};