#include "CLWorkItem.hpp"

namespace MATD {
	namespace ENGINE {
		namespace OPENCL {
			WorkItem::WorkItem(Kernel* kernel): MATD::WorkItem(kernel) {
				MATD_CORE_TRACE("CL_WORKITEM::Work Item created with OpenCL");
			}

			void WorkItem::AddToQueue()
			{
			}

			void WorkItem::OnComplete()
			{
			}
		}
	}
}