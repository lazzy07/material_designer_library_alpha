#include "Buffer.hpp"
#include "../../core/Log.hpp"

namespace MATD {
		template<typename T>
		Buffer<T>::Buffer(T* buffer, size_t size)
		{
			SetBuffer(buffer, size);
		}

		template<typename T>
		void Buffer<T>::SetBuffer(T* val, size_t size) {
			m_Value = val;
			m_Size = size;
			m_ElementSize = sizeof(T);
			m_ByteSize = m_ElementSize * size;
		}
}