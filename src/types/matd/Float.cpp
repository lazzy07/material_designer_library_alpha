#include "Float.hpp"
#include "../../core/Log.hpp"

namespace MATD {
	namespace DTYPES {
		Float::Float(float val) : m_Value(val)
		{
			MATD_CORE_TRACE("MATD_INT::Created mat_float:{}", val);
		}
	}
}