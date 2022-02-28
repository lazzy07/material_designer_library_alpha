#include "CLColorVec3.hpp"
#include "../../../core/Log.hpp"
#include "../../../engine/matd/Kernel.hpp"
#include "../../../engine/vendor/opencl/CLWorkItem.hpp"
#include <memory>

namespace MATD {
	namespace DTYPES {
		namespace OPENCL {
			ColorVec3::ColorVec3(MATD::ColorVec3 val) : MATD::MatColorVec3(val) {
				MATD_CORE_TRACE("CL_FLOAT:::Created CL ColorVec3 B:{} G:{} R:{}", val.b, val.g, val.r);
			}

			void ColorVec3::Bind(WorkItem* workItem, size_t index)
			{
				const MATD::ENGINE::OPENCL::Kernel* kernel = (ENGINE::OPENCL::Kernel*)workItem->GetKernel();
				cl::Kernel clKernel = kernel->GetCLKernel();
				clKernel.setArg<MATD::ColorVec3>(index, GetVal());
				MATD_CORE_TRACE("CL_ColorVec3::ColorVec3 value bound to kernel:{} at index:{}", kernel->GetID(), index);
			}

			void ColorVec3::Delete()
			{
			}

			void ColorVec3::AddToQueue(MATD::Queue* queue)
			{
			}
		}
	}
}