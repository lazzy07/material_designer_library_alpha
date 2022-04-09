#pragma once
#include "Image.hpp"

namespace MATD {
  enum class MATD_TEXTURE_TYPE {
    TEX_8BIT,
    TEX_16BIT,
    TEX_32BIT
  };

  namespace DTYPES{
    class Texture {
    public:
      Texture(size_t size, size_t elem_size, size_t width, size_t height, buf_type argType);
    private:
      Ref<Image> m_Image;
      void* m_Buffer;
    };
  }
}