#pragma once
#include "Argument.hpp"

namespace MATD{
  template <typename T>
  class Buffer : public DTYPES::Argument {
  public:
    Buffer(T* buffer, size_t size);

    void SetBuffer(T* val, size_t size);

    T* GetBuffer();
    const size_t GetSize();
    const size_t GetByteSize();
    const size_t GetElementSize();

    void Bind(const ENGINE::WorkItem* workItem, size_t index);
    void Delete();
  };
}