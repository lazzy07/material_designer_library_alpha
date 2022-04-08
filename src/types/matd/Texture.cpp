#include "Texture.hpp"
#include "Argument.hpp"

MATD::DTYPES::Texture::Texture(size_t size, size_t elem_size, size_t width, size_t height, buf_type argType)
{
	auto image = MATD::Argument::Image(m_Buffer, size, elem_size, width, height, argType);
	m_Image.reset(image);
}