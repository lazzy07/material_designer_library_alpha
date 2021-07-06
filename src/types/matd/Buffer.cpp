#include "Buffer.hpp"
#include "../../core/Log.hpp"

namespace MATD {
		Buffer::Buffer(void* buffer, size_t size, size_t elem_size, buf_type argType): Argument(MAT_ARG::MAT_BUFFER), m_Value(buffer) ,m_ElementSize(elem_size), m_Size(size), m_BufType(argType)
		{
			m_ByteSize = m_ElementSize * size;
		}

		void Buffer::SetBuffer(void* val, size_t size, size_t elem_size) {
			m_Value = val;
			m_Size = size;
			m_ElementSize = elem_size;
			m_ByteSize = m_ElementSize * size;
		}
}