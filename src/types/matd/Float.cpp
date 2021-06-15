#include "Float.hpp"
#include "../../core/Log.hpp"
#include "..\vendor\opencl\CLFloat.hpp"

namespace MATD {
		Float::Float(float val) : m_Value(val)
		{
			MATD_CORE_TRACE("MATD_INT::Created mat_float:{}", val);
		}

		void DTYPES::OPENCL::Float::Bind(const ENGINE::WorkItem* workItem, size_t index)
		{
		}

		void DTYPES::OPENCL::Float::Delete()
		{
		}
}