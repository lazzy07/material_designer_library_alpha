#include "Float.hpp"
#include "../../core/Log.hpp"
#include "..\vendor\opencl\CLFloat.hpp"

namespace MATD {
		Float::Float(float val) : Argument(MAT_ARG::MAT_FLOAT), m_Value(val)
		{
		}
}