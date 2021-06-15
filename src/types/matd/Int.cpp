#include "Int.hpp"
#include "../../core/Log.hpp"

namespace MATD {
		Int::Int(int val): m_Value(val)
		{
			MATD_CORE_TRACE("MATD_INT::Created mat_integer:{}", val);
		}
}