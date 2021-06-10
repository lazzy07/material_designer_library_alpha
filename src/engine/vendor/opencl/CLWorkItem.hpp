#pragma once
#include "../../matd/WorkItem.hpp"
#include "CLKernel.hpp"
#include <CL/cl.hpp>

namespace MATD {
	namespace ENGINE {
		namespace OPENCL {
			class WorkItem : public ENGINE::WorkItem {
			public:
				WorkItem(Ref<Kernel> kernel);
				
			private:
				Ref<OPENCL::Kernel> m_Kernel;
			};
		}
	}
}