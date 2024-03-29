#include "ColorTexture.hpp"

MATD::ColorTexture::ColorTexture(const MATD_TEXTURE_BIT_TYPE bitType, const size_t width, const size_t height, const buf_type argType) : Texture(MAT_ARG::MAT_TEXCOLOR, bitType, 4,width, height, argType)
{
}

MATD::ColorTexture::~ColorTexture()
{
	MATD_CORE_TRACE("MATD::TEX ColorTexture deleted");
}
