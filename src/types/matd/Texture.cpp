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
	}

	return 8;
}

MATD::DTYPES::Texture::Texture(const MAT_ARG matArgType, const MATD_TEXTURE_BIT_TYPE bitType, const size_t noOfChannels, const size_t width, const size_t height, buf_type argType) : DTYPES::Argument(matArgType),
	m_Size(width * height * noOfChannels), m_ElementSize(Texture::BitTypeToSize(bitType)),
	m_ByteSize(m_ElementSize * m_Size), m_Width(width), m_Height(height), m_NoOfChannels(noOfChannels), m_BitType(bitType), m_BufType(argType)
{
	m_Buffer = malloc(m_Size * m_ElementSize);
}

MATD::DTYPES::Texture::~Texture()
{
	free(m_Buffer);
}

MATD::MATD_TEXTURE_BIT_TYPE MATD::DTYPES::Texture::GetBitType() const
{ return m_BitType; }

size_t MATD::DTYPES::Texture::GetHeight() const
{ return m_Height; }

size_t MATD::DTYPES::Texture::GetWidth() const
{ return m_Width; }

size_t MATD::DTYPES::Texture::GetNoOfChannels() const
{ return m_NoOfChannels; }

void MATD::DTYPES::Texture::ChangeImageProperties(MATD_TEXTURE_BIT_TYPE bitType, size_t noOfChannels, size_t width, size_t height)
{
	m_Size = width * height * noOfChannels;
	m_ElementSize = Texture::BitTypeToSize(bitType);

	m_BitType = bitType;
	m_NoOfChannels = noOfChannels;
	m_Width = width;
	m_Height = height;

	m_Buffer = realloc(m_Buffer, m_ElementSize * m_Size);
}
