#include "Device.hpp"
#include "../../core/Log.hpp"

MATD::ENGINE::Device::Device(std::string deviceName, DEVICE_TYPE type)
{
	m_DeviceName = deviceName;
	m_DeviceType = type;
	MATD_CORE_TRACE("MATD_DEVICE:: Device initialized name: {} type: {}", m_DeviceName, m_DeviceType == DEVICE_TYPE::DEVICE_CPU? "CPU" : "GPU");
}
