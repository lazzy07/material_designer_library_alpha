#include "Float.hpp"
#include "../../core/Log.hpp"
#include "..\vendor\opencl\CLFloat.hpp"

namespace MATD {
		Float::Float(size_t id, float val) : m_Value(val), Argument(id)
		{
		}

		void DTYPES::OPENCL::Float::Bind(const WorkItem* workItem, size_t index)
		{
		}

		void DTYPES::OPENCL::Float::Delete()
		{
		}
}