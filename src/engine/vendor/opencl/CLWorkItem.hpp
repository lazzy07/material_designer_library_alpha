#pragma once
#include "../../matd/WorkItem.hpp"
#include "CLKernel.hpp"
#include "../../matd/Queue.hpp"
#include "../../../types/vendor/opencl/CLBuffer.hpp"

namespace MATD {
	namespace ENGINE {
		namespace OPENCL {
			class WorkItem : public MATD::WorkItem {
			public:
				WorkItem(Kernel* kernel);
				void AddToQueue(MATD::Queue* queue) override;
				void OnComplete() override;
				void SetOutput(size_t index, DTYPES::Argument* argument) override;
			};
		}
	}
}