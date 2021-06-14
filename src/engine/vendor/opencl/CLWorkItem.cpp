#include "CLWorkItem.hpp"

namespace MATD {
	namespace ENGINE {
		namespace OPENCL {
			WorkItem::WorkItem(Ref<ENGINE::Kernel> kernel) {
				m_Kernel = std::static_pointer_cast<OPENCL::Kernel>(kernel);
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