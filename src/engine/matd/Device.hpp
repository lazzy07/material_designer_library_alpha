#pragma once
#include <string>

namespace MATD{
  namespace ENGINE{
    enum class MAT_DEVICE_TYPE {
      DEVICE_GPU,
      DEVICE_CPU
    };

    /**
     * @brief Material Designer device class, used to store device information and run kernels on the device
     * 
     */
    class Device{
    public:
      /**
       * @brief Construct a new Device object
       * 
       * @param deviceName Name of the device
       * @param type GPU or CPU
       */
      Device(std::string deviceName, MATD::ENGINE::MAT_DEVICE_TYPE type);

      inline void SetDeviceName(const std::string name) { m_DeviceName = name; };
      inline void SetDeviceType(ENGINE::MAT_DEVICE_TYPE type) { m_DeviceType = type; };
      inline std::string GetDeviceName() const { return m_DeviceName; };

      inline size_t GetId() const { return m_Id; };
      inline void SetId(size_t id) { m_Id = id; };
    private:
      size_t m_Id;
      std::string m_DeviceName;
      ENGINE::MAT_DEVICE_TYPE m_DeviceType = ENGINE::MAT_DEVICE_TYPE::DEVICE_CPU;
      
    };
  };
}