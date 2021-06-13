#pragma once
#include "../../matd/WorkItem.hpp"
#include "CLKernel.hpp"
#include <CL/cl.hpp>

namespace MATD {
	namespace ENGINE {
		namespace OPENCL {
			class WorkItem : public ENGINE::WorkItem {
			public:
				WorkItem(Ref<ENGINE::Kernel> kernel);
				virtual void AddToQueue() override;
				virtual void SetArgument(Argument argument) override;
				virtual void OnComplete() override;
			private:
				Ref<ENGINE::Kernel> m_Kernel;
			};
		}
	}
}