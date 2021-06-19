#pragma once
#include "Argument.hpp"

namespace MATD{
    class Buffer : public DTYPES::Argument {
    public:
      Buffer(void* buffer, size_t size, size_t elem_size, buf_type argType);

      void SetBuffer(void* val, size_t size, size_t elem_size);

      inline void* GetBuffer() { return m_Value; };
			inline const size_t GetSize() const { return m_Size; };
			inline const size_t GetByteSize() const { return m_ByteSize; };
			inline const size_t GetElementSize() const { return m_ElementSize; };
      
			virtual void Bind(const WorkItem* workItem, size_t index) = 0;
			virtual void Delete() = 0;
    private:
      buf_type m_BufType;
      void* m_Value;
      size_t m_ByteSize = 0;
      size_t m_Size = 0;
      size_t m_ElementSize = 0;
    };
}