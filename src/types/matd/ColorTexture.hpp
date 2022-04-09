#pragma once
#include "Texture.hpp"

namespace MATD{
    class ColorTexture : public DTYPES::Texture {
    public:
      ColorTexture(size_t size, size_t elem_size, size_t width, size_t height, buf_type argType);
    };
}