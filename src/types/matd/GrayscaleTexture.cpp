#include "GrayscaleTexture.hpp"

MATD::GrayscaleTexture::GrayscaleTexture(MATD_TEXTURE_BIT_TYPE bitType, size_t width, size_t height, buf_type argType) : Texture(bitType, 1, width, height, argType)
{
}
