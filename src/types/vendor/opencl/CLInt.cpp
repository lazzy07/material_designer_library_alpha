#include "CLInt.hpp"
#include "../../../core/Log.hpp"
#include "../../../engine/matd/Kernel.hpp"
#include "../../../engine/vendor/opencl/CLWorkItem.hpp"
#include <memory>

namespace MATD {
	namespace DTYPES {
		namespace OPENCL {
			Int::Int(size_t id, int val): MATD::Int(id, val) {
				MATD_CORE_TRACE("CL_INT:::Created CL Int id:{} val:{}", id, val);
			}

			void Int::Bind(const WorkItem* workItem)
			{
				const MATD::ENGINE::OPENCL::Kernel* kernel = (ENGINE::OPENCL::Kernel*)workItem->GetKernel();
				cl::Kernel clKernel = kernel->GetCLKernel();
				clKernel.setArg<int>(GetID(), GetVal());
				MATD_CORE_TRACE("CL_INT::Integer value bound to kernel:{} at index:{}", kernel->GetID(), GetID());
			};

			void Int::Delete()
			{
			}
		}
	}
}