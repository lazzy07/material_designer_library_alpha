#pragma once
#include "Argument.hpp"

namespace MATD{
  namespace DTYPES{
    template <typename T>
    class Buffer : public Argument {
    public:
      Buffer(T* buffer, size_t size);

      void SetBuffer(T* val, size_t size);

      inline T* GetBuffer() { return m_Value; };
			inline const size_t GetSize() const { return m_Size; };
			inline const size_t GetByteSize() const { return m_ByteSize; };
			inline const size_t GetElementSize() const { return m_ElementSize; };
    private:
      T* m_Value;
      size_t m_ByteSize = 0;
      size_t m_Size = 0;
      size_t m_ElementSize = sizeof(T);
    };
  }
}