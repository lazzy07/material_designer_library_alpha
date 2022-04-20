#include "ColorTexture.hpp"

MATD::ColorTexture::ColorTexture(const MATD_TEXTURE_BIT_TYPE bitType, const size_t width, const size_t height, const buf_type argType) : Texture(MAT_ARG::MAT_TEXCOLOR, bitType, 3,width, height, argType)
{
}