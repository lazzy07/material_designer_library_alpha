#pragma once

namespace MATD {
	class Int;
	class Float;
	class Buffer;
	class Image;

	class WorkItem;

	class Argument {
		public:
			static MATD::Int* Int(int val);
			static MATD::Float* Float(float val);
			static MATD::Buffer* Buffer(void* val, size_t size, size_t elem_size);
			static MATD::Image* Image(void* val, size_t size, size_t elem_size, size_t width, size_t height);
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