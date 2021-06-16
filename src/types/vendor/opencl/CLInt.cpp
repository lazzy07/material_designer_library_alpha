#include "CLInt.hpp"
#include "../../../core/Log.hpp"

namespace MATD {
	namespace DTYPES {
		namespace OPENCL {
			Int::Int(size_t id, int val): MATD::Int(id, val) {
				MATD_CORE_TRACE("CL_INT:::Created CL Int id:{} val:{}", id, val);
			}

			void Int::Bind(const WorkItem* workItem, size_t index)
			{
			}

			void Int::Delete()
			{
			}
		}
	}
}