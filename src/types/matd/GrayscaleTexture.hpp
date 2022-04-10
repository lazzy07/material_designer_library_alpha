#pragma once
#include "Texture.hpp"

namespace MATD{
    class GrayscaleTexture : public DTYPES::Texture {
    public:
      GrayscaleTexture(MATD_TEXTURE_BIT_TYPE bitType, size_t width, size_t height, buf_type argType);

    };
}