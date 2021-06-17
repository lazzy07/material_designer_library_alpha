#pragma once
#include "Argument.hpp"

namespace MATD{
  template<typename T>
  class Image : public DTYPES::Argument {
  public:
    Image(size_t id, T* buffer, size_t size, size_t width, size_t height);

    inline T* GetImageData() { return m_Value; };
    inline const size_t GetSize() const { return m_Size; };
    inline const size_t GetByteSize() const { return m_ByteSize; };
    inline const size_t GetElementSize() const { return m_ElementSize; };

    virtual void Bind(const WorkItem* workItem) = 0;
    virtual void Delete() = 0;
  private:
    T* m_Value;
    size_t m_Size = 0;
    size_t m_ElementSize = 0;
    size_t m_ByteSize = 0;

    size_t m_Width = 0;
    size_t m_Height = 0;
  };
}