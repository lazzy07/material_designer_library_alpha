#include "CLDevice.hpp"
#include <memory>
#include "CLContext.hpp"

namespace MATD{
	namespace ENGINE {
		namespace OPENCL {
			Device::Device(std::string deviceName, ENGINE::MAT_DEVICE_TYPE type): ENGINE::Device(deviceName, type) {
				
			}

			void Device::InitDevice() {
				m_Context = std::make_shared<OPENCL::Context>(m_Device, GetDeviceName());
			}

			void Device::SetCLDeviceData(cl::Device device, cl_uint maxUnits, cl_uint maxDim, std::vector<size_t> maxItem, cl_uint grpSize)
			{
				m_Device = device;
				m_DeviceMaxComputeUnits = maxUnits;
				m_DeviceMaxWorkItemDimensions = maxDim;
				m_DeviceMaxWorkItemSizes = maxItem;
				m_DeviceMaxGroupSize = grpSize;
			}
		}
	}
}
