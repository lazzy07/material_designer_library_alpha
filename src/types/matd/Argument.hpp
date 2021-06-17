#pragma once 
#include <string>


namespace MATD {
	class Int;
	class Float;
		
	template<typename T>
	class Buffer;

	template<typename T>
	class Image;

	class WorkItem;

	class Argument {
		public:
		static Int* Int(int val);
		static Float* Float(float val);

		template<typename T>
		static Buffer<T>* Buffer(T* val, size_t size);

		template<typename T>
		static Image<T>* Image(T* val, size_t size, size_t width, size_t height);
	};

	namespace DTYPES {
		class Argument {
		public:
			Argument();
			virtual void Bind(const WorkItem* workItem, size_t index) = 0;
			virtual void Delete() = 0;
		};
	}
}