#pragma once
#include "Argument.hpp"

namespace MATD{
  template<typename T>
  class Image : public Argument {
  public:
    Image(T* buffer, size_t size, size_t width, size_t height);

    T* GetImageData();
    const size_t GetSize();
    const size_t GetByteSize();
    const size_t GetElementSize();

    void Bind(const WorkItem* workItem, size_t index);
    void Delete();
  };
}