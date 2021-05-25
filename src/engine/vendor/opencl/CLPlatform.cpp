#include "CLPlatform.hpp"
#include <CL/opencl.h>
#include "CLDevice.hpp"

namespace MATD{
  namespace ENGINE{
    namespace OPENCL{
      

      std::vector<Ref<MATD::ENGINE::Device>> Platform::GetCompatibleDevices(){
        std::vector<Ref<MATD::ENGINE::Device>> devices;
        cl_int error = 0;
        cl_uint numOfDevices = 0;

        error = clGetDeviceIDs(m_PlatformId, CL_DEVICE_TYPE_ALL, 0, NULL, &numOfDevices);

        if(error != CL_SUCCESS){
          MATD_CORE_ERROR("Couldn't find any device that support OpenCL");
        }
        MATD_CORE_TRACE("MATD_CLPLATFORM:: Platform: {} Devices: {}", GetName(), numOfDevices);

        m_DeviceIds = (cl_device_id*)malloc(sizeof(cl_device_id) * numOfDevices);

        error = clGetDeviceIDs(m_PlatformId, CL_DEVICE_TYPE_ALL, numOfDevices, m_DeviceIds, &numOfDevices);

        for(cl_uint i=0; i<numOfDevices; i++){
          cl_int error = 0;
          size_t paramSize = 0;

          error = clGetDeviceInfo(m_DeviceIds[i], CL_DEVICE_NAME, 0, NULL, &paramSize);
          char* deviceName = (char *)malloc(sizeof(char) * paramSize);
          error = clGetDeviceInfo(m_DeviceIds[i], CL_DEVICE_NAME, paramSize, deviceName, NULL);

          error = clGetDeviceInfo(m_DeviceIds[i], CL_DEVICE_TYPE, 0, NULL, &paramSize);
          cl_device_type* deviceType = (cl_device_type*)malloc(sizeof(cl_device_type) * paramSize);
          error = clGetDeviceInfo(m_DeviceIds[i], CL_DEVICE_TYPE, paramSize, deviceType, NULL);

          error = clGetDeviceInfo(m_DeviceIds[i], CL_DEVICE_VENDOR_ID, 0, NULL, &paramSize);
          cl_uint* deviceVendorId = (cl_uint *)malloc(sizeof(cl_uint) * paramSize);
          error = clGetDeviceInfo(m_DeviceIds[i], CL_DEVICE_VENDOR_ID, paramSize, deviceVendorId, NULL);

          error = clGetDeviceInfo(m_DeviceIds[i], CL_DEVICE_MAX_COMPUTE_UNITS, 0, NULL, &paramSize);
          cl_uint* deviceMaxComputeUnits = (cl_uint*)malloc(sizeof(cl_uint) * paramSize);
          error = clGetDeviceInfo(m_DeviceIds[i], CL_DEVICE_MAX_COMPUTE_UNITS, paramSize, deviceMaxComputeUnits, NULL);

          error = clGetDeviceInfo(m_DeviceIds[i], CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS, 0, NULL, &paramSize);
          cl_uint* deviceMaxWorkItemDimensions = (cl_uint *)malloc(sizeof(cl_uint) * paramSize);
          error = clGetDeviceInfo(m_DeviceIds[i], CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS, paramSize, deviceMaxWorkItemDimensions, NULL);

          error = clGetDeviceInfo(m_DeviceIds[i], CL_DEVICE_MAX_WORK_ITEM_SIZES, 0, NULL, &paramSize);
          cl_uint* deviceMaxWorkItemSizes = (cl_uint *)malloc(sizeof(cl_uint) * paramSize);
          error = clGetDeviceInfo(m_DeviceIds[i], CL_DEVICE_MAX_WORK_ITEM_SIZES, paramSize, deviceMaxWorkItemSizes, NULL);

          error = clGetDeviceInfo(m_DeviceIds[i], CL_DEVICE_MAX_WORK_GROUP_SIZE, 0, NULL, &paramSize);
          cl_uint* deviceMaxGroupSize = (cl_uint *)malloc(sizeof(cl_uint) * paramSize);
          error = clGetDeviceInfo(m_DeviceIds[i], CL_DEVICE_MAX_WORK_GROUP_SIZE, paramSize, deviceMaxWorkItemSizes, NULL);

          std::string dname(deviceName);
          DEVICE_TYPE type;

          switch (*deviceType) {
          case CL_DEVICE_TYPE_CPU:
            type = DEVICE_TYPE::DEVICE_CPU;
            break;
          case CL_DEVICE_TYPE_GPU:
            type = DEVICE_TYPE::DEVICE_GPU;
            break;
          default:
            MATD_CORE_ASSERT(false, "Unknown device type found");
          }

          Ref<OPENCL::Device> device = std::make_shared<OPENCL::Device>(dname, type);
          device->SetCLDeviceData(m_DeviceIds[i], *deviceMaxComputeUnits, *deviceMaxWorkItemDimensions, *deviceMaxWorkItemSizes, *deviceMaxGroupSize);
          devices.push_back(device);

          free(deviceName);
          free(deviceType);
          free(deviceMaxComputeUnits);
          free(deviceMaxWorkItemDimensions);
          free(deviceMaxWorkItemSizes);
          free(deviceMaxGroupSize);
        }


        return devices;
      }
    }
  }
}