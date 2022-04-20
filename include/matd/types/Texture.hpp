#pragma once
#include "Argument.hpp"

namespace MATD {
  enum class MATD_TEXTURE_BIT_TYPE {
    TEX_8BIT,
    TEX_16BIT,
    TEX_32BIT
  };

  namespace DTYPES{
    class Texture : DTYPES::Argument {
    public:
      static size_t BitTypeToSize(MATD_TEXTURE_BIT_TYPE bitType);

      Texture(MAT_ARG matArgType, MATD_TEXTURE_BIT_TYPE bitType, size_t noOfChannels, size_t width, size_t height, buf_type argType);
      ~Texture();

      [[nodiscard]] MATD_TEXTURE_BIT_TYPE GetBitType() const;
      [[nodiscard]] size_t GetHeight() const;
      [[nodiscard]] size_t GetWidth() const;
      [[nodiscard]] size_t GetNoOfChannels() const;
      [[nodiscard]] size_t GetSize() const { return m_Size; }
      [[nodiscard]] size_t GetByteSize() const { return m_ByteSize; }
      [[nodiscard]] size_t GetElementSize() const { return m_ElementSize; }

      [[nodiscard]] void* GetBuffer() const { return m_Buffer; }

      void Bind(WorkItem* workItem, size_t index) override = 0;
      void Delete() override = 0;
      void AddToQueue(MATD::Queue* queue) override = 0;

      void ChangeImageProperties(MATD_TEXTURE_BIT_TYPE bitType, size_t noOfChannels, size_t width, size_t height);
    private:
      void* m_Buffer = nullptr;
      buf_type m_BufType;
      size_t m_Size = 0;
      size_t m_ElementSize = 0;
      size_t m_ByteSize = 0;

      size_t m_Width;
      size_t m_Height;
      size_t m_NoOfChannels;
      MATD_TEXTURE_BIT_TYPE m_BitType;
    };

  }
}