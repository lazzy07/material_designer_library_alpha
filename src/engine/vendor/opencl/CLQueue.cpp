#include "CLQueue.hpp"
#include "CLDevice.hpp"
#include "../../../core/EngineManager.hpp"
#include "../../../core/Core.hpp"

namespace MATD {
	namespace ENGINE {
		namespace OPENCL {
			Queue::Queue() : MATD::Queue() {
				Ref<ENGINE::Device> device = CORE::EngineManager::GetEngineInstance()->GetSelectedDevice();
				auto clDevice = std::static_pointer_cast<ENGINE::OPENCL::Device>(device);
				auto clContext = clDevice->GetContext();
				m_Queue = cl::CommandQueue(clContext->GetCLContext(), clDevice->GetClDevice());
				MATD_CORE_TRACE("MATD_CLQUEUE:::Queue initiated");
			}

			Queue::~Queue()
			{
				MATD_CORE_TRACE("MATD_CLQUEUE:::Queue deleted");
			}
		}
	}
}