#include "Texture.hpp"
#include "Argument.hpp"

size_t MATD::DTYPES::Texture::BitTypeToSize(MATD_TEXTURE_BIT_TYPE bitType)
{
	switch (bitType)
	{
	case MATD::MATD_TEXTURE_BIT_TYPE::TEX_8BIT:
		return 8;
	case MATD::MATD_TEXTURE_BIT_TYPE::TEX_16BIT:
		return 16;
	case MATD::MATD_TEXTURE_BIT_TYPE::TEX_32BIT:
		return 32;
	default:
		return 8;
	}
}

MATD::DTYPES::Texture::Texture(MATD_TEXTURE_BIT_TYPE bitType, size_t noOfChannels, size_t width, size_t height, buf_type argType) : m_BitType(bitType), m_Height(height), m_Width(width), m_NoOfChannels(noOfChannels)
{
	int size = width * height * noOfChannels;
	int elem_size = Texture::BitTypeToSize(bitType);

	m_Buffer = malloc(elem_size * size);
	
	auto image = MATD::Argument::Image(m_Buffer, size, elem_size, width, height, argType);
	m_Image.reset(image);
}

MATD::DTYPES::Texture::~Texture()
{
	delete m_Buffer;
}

void MATD::DTYPES::Texture::ChangeImageProperties(MATD_TEXTURE_BIT_TYPE bitType, size_t noOfChannels, size_t width, size_t height)
{
	int size = width * height * noOfChannels;
	int elem_size = Texture::BitTypeToSize(bitType);

	m_Buffer = realloc(m_Buffer, elem_size * size);
}
