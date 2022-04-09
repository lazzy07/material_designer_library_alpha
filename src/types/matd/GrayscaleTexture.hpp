#pragma once
#include "Texture.hpp"

namespace MATD{
    class GrayscaleTexture : public DTYPES::Texture {
    public:
      GrayscaleTexture(size_t size, size_t elem_size, size_t width, size_t height, buf_type argType);

    };
}