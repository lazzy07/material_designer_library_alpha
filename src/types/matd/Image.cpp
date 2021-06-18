#include "Image.hpp"


namespace MATD {
		Image::Image(void* buffer, size_t size, size_t elem_size, size_t width, size_t height, buf_type argType):
			m_Value(buffer), m_Height(height), m_Width(width), m_Size(size), m_ElementSize(elem_size), m_BufType(argType)
		{
			m_ByteSize = m_ElementSize * size;
		}
}