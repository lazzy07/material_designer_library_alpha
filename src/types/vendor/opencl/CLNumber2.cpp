#include "CLNumber2.hpp"
#include "../../../core/Log.hpp"
#include "../../../engine/matd/Kernel.hpp"
#include "../../../engine/vendor/opencl/CLWorkItem.hpp"
#include <memory>

namespace MATD {
	namespace DTYPES {
		namespace OPENCL {
			Number2::Number2(MATD::Number2 val) : MATD::MatNumber2(val) {
				MATD_CORE_TRACE("CL_FLOAT:::Created CL Number2 X:{} Y:{}", val.x, val.y);
			}

			void Number2::Bind(WorkItem* workItem, size_t index)
			{
				const MATD::ENGINE::OPENCL::Kernel* kernel = (ENGINE::OPENCL::Kernel*)workItem->GetKernel();
				cl::Kernel clKernel = kernel->GetCLKernel();
				clKernel.setArg<MATD::Number2>(index, GetVal());
				MATD_CORE_TRACE("CL_ColorVec3::ColorVec3 value bound to kernel:{} at index:{}", kernel->GetID(), index);
			}

			void Number2::Delete()
			{
			}

			void Number2::AddToQueue(MATD::Queue* queue)
			{
			}
		}
	}
}