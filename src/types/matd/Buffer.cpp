#include "Buffer.hpp"
#include "../../core/Log.hpp"

namespace MATD {
		Buffer::Buffer(void* buffer, size_t size, size_t elem_size): m_ElementSize(elem_size)
		{
			SetBuffer(buffer, size, elem_size);
		}

		void Buffer::SetBuffer(void* val, size_t size, size_t elem_size) {
			m_Value = val;
			m_Size = size;
			m_ElementSize = elem_size;
			m_ByteSize = m_ElementSize * size;
		}
}