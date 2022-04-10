#pragma once
#include "Texture.hpp"

namespace MATD{
    class ColorTexture : public DTYPES::Texture {
    public:
      ColorTexture(MATD_TEXTURE_BIT_TYPE bitType, size_t width, size_t height, buf_type argType);
    };
}