#include "GrayscaleTexture.hpp"

MATD::GrayscaleTexture::GrayscaleTexture(const MATD_TEXTURE_BIT_TYPE bitType, const size_t width, const size_t height, const buf_type argType) : Texture(MAT_ARG::MAT_TEXGRAYSCALE, bitType, 1, width, height, argType)
{
}
