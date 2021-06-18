#pragma once
#include "../../matd/WorkItem.hpp"
#include "CLKernel.hpp"
#include <CL/cl.hpp>

namespace MATD {
	namespace ENGINE {
		namespace OPENCL {
			class WorkItem : public MATD::WorkItem {
			public:
				WorkItem(Kernel* kernel);
				virtual void AddToQueue() override;
				virtual void OnComplete() override;
				virtual void SetOutput(Buffer* buffer) override;
				virtual void SetOutput(Image* image) override;
			};
		}
	}
}