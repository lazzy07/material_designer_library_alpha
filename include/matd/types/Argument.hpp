
namespace MATD{
  namespace DTYPES{
    class Argument{
      static Int(int val);
      static Float(int val);

      template<typename T>
      static Buffer(T* data, size_t size);

      template<typename T>
      static Image(T* data, size_t size, size_t height, size_t width);
    }
  }
}