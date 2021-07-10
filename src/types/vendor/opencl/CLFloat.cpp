#include "CLFloat.hpp"
#include "../../../core/Log.hpp"
#include "../../../engine/matd/Kernel.hpp"
#include "../../../engine/vendor/opencl/CLWorkItem.hpp"
#include <memory>

namespace MATD {
	namespace DTYPES {
		namespace OPENCL {
			Float::Float(float val): MATD::Float(val) {
				MATD_CORE_TRACE("CL_FLOAT:::Created CL Float val:{}", val);
			}



			void Float::Bind(WorkItem* workItem, size_t index)
			{
				const MATD::ENGINE::OPENCL::Kernel* kernel = (ENGINE::OPENCL::Kernel*)workItem->GetKernel();
				cl::Kernel clKernel = kernel->GetCLKernel();
				clKernel.setArg<float>(index, GetVal());
				MATD_CORE_TRACE("CL_INT::Integer value bound to kernel:{} at index:{}", kernel->GetID(), index);
			}

			void Float::Delete()
			{
			}

			void Float::AddToQueue(MATD::Queue* queue)
			{
			}
		}
	}
}