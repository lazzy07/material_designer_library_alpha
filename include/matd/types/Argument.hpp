#pragma once
#include "../engine/matd/WorkItem.hpp"

namespace MATD{
  class Int;
  class Float;

  template<typename T>
  class Buffer;
  
  template<typename T>
  class Image;

  class Argument {
  public:
    static MATD::Int* Int(int val);
    static MATD::Float* Float(float val);

    template<typename T>
    static MATD::Buffer<T>* Buffer(T* data, size_t size);

    template<typename T>
    static MATD::Image<T>* Image(T* data, size_t size, size_t height, size_t width);
  };

  namespace DTYPES{
    class Argument {
    public:
      inline const size_t& GetID();
      inline void SetID(const size_t& ID);

      virtual void Bind(const ENGINE::WorkItem* workItem, size_t index) = 0;
      virtual void Delete() = 0;
    };
  }
}