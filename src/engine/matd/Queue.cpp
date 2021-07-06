#include "Queue.hpp"
#include "../../core/EngineManager.hpp"
#include "../vendor/opencl/CLQueue.hpp"

namespace MATD {
	Queue* Queue::CreateQueue()
	{
		CORE::SUPPORTED_ENGINES engine = CORE::EngineManager::GetSelectedEngine();

		switch (engine) {
		case CORE::SUPPORTED_ENGINES::CUDA:
			MATD_CORE_ASSERT(false, "ARGUMENT::CUDA not supported yet");
			break;
		case CORE::SUPPORTED_ENGINES::OPEN_CL:
			return new MATD::ENGINE::OPENCL::Queue();
			break;
		}

		return nullptr;
	}

	Queue::Queue() {

	};

	Queue::~Queue() {

	}
}
