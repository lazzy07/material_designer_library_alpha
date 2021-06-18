#include "CLWorkItem.hpp"
#include "CLDevice.hpp"
#include "../../../core/EngineManager.hpp"

namespace MATD {
	namespace ENGINE {
		namespace OPENCL {
			WorkItem::WorkItem(Kernel* kernel): MATD::WorkItem(kernel) {
				MATD_CORE_TRACE("CL_WORKITEM::Work Item created with OpenCL");
			}

			void WorkItem::AddToQueue()
			{
				Ref<ENGINE::Device> device = CORE::EngineManager::GetEngineInstance()->GetSelectedDevice();
				auto clDevice = std::static_pointer_cast<ENGINE::OPENCL::Device>(device);
				cl::CommandQueue queue = clDevice->GetClQueue();
			}

			void WorkItem::OnComplete()
			{
			}

			void WorkItem::SetOutput(Buffer* buffer)
			{

			}

			void WorkItem::SetOutput(Image* image)
			{

			}
		}
	}
}