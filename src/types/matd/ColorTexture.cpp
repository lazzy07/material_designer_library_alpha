#include "ColorTexture.hpp"

MATD::ColorTexture::ColorTexture(MATD_TEXTURE_BIT_TYPE bitType, size_t width, size_t height, buf_type argType) : Texture(bitType, 3,width, height, argType)
{
}