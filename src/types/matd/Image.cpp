#include "Image.hpp"


namespace MATD {
		template<typename T>
		Image<T>::Image(T* buffer, size_t size, size_t width, size_t height): m_Value(buffer), m_Height(height), m_Width(width), m_Size(size)
		{
			m_ElementSize = sizeof(T);
			m_ByteSize = m_ElementSize * size;
		}
}