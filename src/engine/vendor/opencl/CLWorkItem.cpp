#include "CLWorkItem.hpp"

namespace MATD {
	namespace ENGINE {
		namespace OPENCL {
			WorkItem::WorkItem(Ref<Kernel> kernel) {
				m_Kernel = kernel;
				MATD_CORE_TRACE("CL_WORKITEM::Work Item created with OpenCL");
			}
		}
	}
}