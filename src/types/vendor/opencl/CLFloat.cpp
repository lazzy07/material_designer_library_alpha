#include "CLFloat.hpp"
#include "../../../core/Log.hpp"

namespace MATD {
	namespace DTYPES {
		namespace OPENCL {
			Float::Float(size_t id, float val): MATD::Float(id, val) {
				MATD_CORE_TRACE("CL_FLOAT:::Created CL Float id:{} val:{}", id, val);
			}



			void Float::Bind(const WorkItem* workItem)
			{
			}

			void Float::Delete()
			{
			}
		}
	}
}