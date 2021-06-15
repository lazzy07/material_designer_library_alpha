#include "Buffer.hpp"
#include "../../core/Log.hpp"

namespace MATD {
	namespace DTYPES {
		template<typename T>
		Buffer<T>::Buffer(T* buffer, size_t size)
		{
			SetBuffer(buffer, size);
			MATD_CORE_TRACE("MATD_BUFFER::Created mat_buffer of size:{}(bytes)", m_ByteSize);
		}

		template<typename T>
		void Buffer<T>::SetBuffer(T* val, size_t size) {
			m_Value = val;
			m_Size = size;
			m_ElementSize = sizeof(T);
			m_ByteSize = m_ElementSize * size;
		}
	}
}