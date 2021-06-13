#include "CLPlatform.hpp"
#include <CL/opencl.h>
#include "CLDevice.hpp"

namespace MATD{
  namespace ENGINE{
    namespace OPENCL{
      std::vector<Ref<MATD::ENGINE::Device>> Platform::GetCompatibleDevices(){
        std::vector<Ref<MATD::ENGINE::Device>> devices;

        m_Platform.getDevices(CL_DEVICE_TYPE_ALL, &m_Devices);

        if (m_Devices.size() <= 0) {
          MATD_CORE_ERROR("Couldn't find any device that support OpenCL in plaform {}", GetName());
        }

        size_t i = 0;
        for (auto device : m_Devices) {
          cl_int error = 0;
          std::string name = device.getInfo<CL_DEVICE_NAME>(&error);
          cl_device_type deviceType = device.getInfo<CL_DEVICE_TYPE>(&error);
          cl_uint vendorID = device.getInfo<CL_DEVICE_VENDOR_ID>(&error);
          cl_uint deviceMaxComputeUnits = device.getInfo<CL_DEVICE_MAX_COMPUTE_UNITS>(&error);
          cl_uint maxWorkItemDimensions = device.getInfo<CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS>(&error);
          std::vector<size_t> deviceMaxWorkItemSizes = device.getInfo<CL_DEVICE_MAX_WORK_ITEM_SIZES>(&error);
          size_t deviceMaxGroupSize = device.getInfo<CL_DEVICE_MAX_WORK_GROUP_SIZE>(&error);

          MAT_DEVICE_TYPE type;

          switch (deviceType) {
          case CL_DEVICE_TYPE_CPU:
            type = MAT_DEVICE_TYPE::DEVICE_CPU;
            break;
          case CL_DEVICE_TYPE_GPU:
            type = MAT_DEVICE_TYPE::DEVICE_GPU;
            break;
          default:
            MATD_CORE_ASSERT(false, "Unknown device type found");
          }

          Ref<OPENCL::Device> d = std::make_shared<OPENCL::Device>(name, type);
          d->SetId(i);
          d->SetCLDeviceData(device, deviceMaxComputeUnits, maxWorkItemDimensions, deviceMaxWorkItemSizes, deviceMaxGroupSize);
          d->CreateContext();
          i++;
        }

        return devices;
      }
    }
  }
}