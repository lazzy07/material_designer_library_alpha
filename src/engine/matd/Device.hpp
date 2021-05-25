#pragma once
#include <string>

namespace MATD{
  namespace ENGINE{
    enum class DEVICE_TYPE {
      DEVICE_GPU,
      DEVICE_CPU
    };

    class Device{
    public:
      Device(std::string deviceName, DEVICE_TYPE type);

      inline void SetDeviceName(const std::string name) { m_DeviceName = name; };
      inline void SetDeviceType(ENGINE::DEVICE_TYPE type) { m_DeviceType = type; };

    private:
      std::string m_DeviceName;
      ENGINE::DEVICE_TYPE m_DeviceType = ENGINE::DEVICE_TYPE::DEVICE_CPU;
    };
  };
}