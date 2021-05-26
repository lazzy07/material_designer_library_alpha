#include "CLDevice.hpp"
#include <memory>
#include "CLContext.hpp"

namespace MATD{
	namespace ENGINE {
		namespace OPENCL {
			Device::Device(std::string deviceName, DEVICE_TYPE type): ENGINE::Device(deviceName, type) {
				
			}

			void Device::CreateContext() {
				m_Context = std::make_shared<OPENCL::Context>(m_DeviceId, GetDeviceName());
			}

			void Device::SetCLDeviceData(cl_device_id id, cl_uint maxUnits, cl_uint maxDim, cl_uint maxItem, cl_uint grpSize)
			{
				m_DeviceId = id;
				m_DeviceMaxComputeUnits = maxUnits;
				m_DeviceMaxWorkItemDimensions = maxDim;
				m_DeviceMaxWorkItemSizes = maxItem;
				m_DeviceMaxGroupSize = grpSize;
			}
		}
	}
}
