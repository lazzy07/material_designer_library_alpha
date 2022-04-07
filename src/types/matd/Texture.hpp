#pragma once
#include "Image.hpp"

namespace MATD{
  namespace DTYPES{
    class Texture {
    public:
      Texture(size_t size, size_t elem_size, size_t width, size_t height, buf_type argType);
    private:
      Ref<Image> m_Image;
    };
  }
}