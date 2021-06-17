#include "Float.hpp"
#include "../../core/Log.hpp"
#include "..\vendor\opencl\CLFloat.hpp"

namespace MATD {
		Float::Float(size_t id, float val) : m_Value(val), Argument(id)
		{
		}
}