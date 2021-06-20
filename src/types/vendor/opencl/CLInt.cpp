#include "CLInt.hpp"
#include "../../../core/Log.hpp"
#include "../../../engine/matd/Kernel.hpp"
#include "../../../engine/vendor/opencl/CLWorkItem.hpp"
#include <memory>

namespace MATD {
	namespace DTYPES {
		namespace OPENCL {
			Int::Int(int val): MATD::Int(val) {
				MATD_CORE_TRACE("CL_INT:::Created CL Int val:{}", val);
			}

			void Int::Bind(WorkItem* workItem, size_t index)
			{
				const MATD::ENGINE::OPENCL::Kernel* kernel = (ENGINE::OPENCL::Kernel*)workItem->GetKernel();
				cl::Kernel clKernel = kernel->GetCLKernel();
				clKernel.setArg<int>(index, GetVal());
				MATD_CORE_TRACE("CL_INT::Integer value bound to kernel:{} at index:{}", kernel->GetID(), index);
			};

			void Int::Delete()
			{
			}
		}
	}
}