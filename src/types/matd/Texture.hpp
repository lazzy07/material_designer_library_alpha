#pragma once
#include "Image.hpp"

namespace MATD {
  enum class MATD_TEXTURE_BIT_TYPE {
    TEX_8BIT,
    TEX_16BIT,
    TEX_32BIT
  };

  namespace DTYPES{
    class Texture {
    public:
      static size_t BitTypeToSize(MATD_TEXTURE_BIT_TYPE bitType);

      Texture(MATD_TEXTURE_BIT_TYPE bitType, size_t noOfChannels, size_t width, size_t height, buf_type argType);
      ~Texture();

			inline MATD_TEXTURE_BIT_TYPE const GetBitType() { return m_BitType; };
			inline size_t const GetHeight() { return m_Height; };
			inline size_t const GetWidth() { return m_Width; };
			inline size_t const GetNoOfChannels() { return m_NoOfChannels; };

      void ChangeImageProperties(MATD_TEXTURE_BIT_TYPE bitType, size_t noOfChannels, size_t width, size_t height);
    private:
      Ref<Image> m_Image;
      void* m_Buffer = nullptr;

      size_t m_Width;
      size_t m_Height;
      size_t m_NoOfChannels;
      MATD_TEXTURE_BIT_TYPE m_BitType;
    };
  }
}