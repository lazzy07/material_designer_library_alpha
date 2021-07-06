#include "CLFloat.hpp"
#include "../../../core/Log.hpp"

namespace MATD {
	namespace DTYPES {
		namespace OPENCL {
			Float::Float(float val): MATD::Float(val) {
				MATD_CORE_TRACE("CL_FLOAT:::Created CL Float val:{}", val);
			}



			void Float::Bind(WorkItem* workItem, size_t index)
			{
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