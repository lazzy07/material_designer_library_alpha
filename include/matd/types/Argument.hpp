#pragma once

#define buf_type int

namespace MATD {
	enum ARG_TYPE {
		DEVICE_READ_WRITE			=	(1 << 0),
		DEVICE_WRITE					=	(1 << 1),
		DEVICE_READ						= (1 << 2),
		DEVICE_USE_HOST_PTR		= (1 << 3),
		DEVICE_ALLOC_HOST_PTR = (1 << 4),
		DEVICE_COPY_HOST_PTR	= (1 << 5),

		HOST_WRITE						= (1 << 7),
		HOST_READ							= (1 << 8),
		HOST_NO_ACCESS				= (1 << 9),
	};

	class Int;
	class Float;
	class Buffer;
	class Image;

	class WorkItem;

	class Argument {
		public:
			static MATD::Int* Int(int val);
			static MATD::Float* Float(float val);
			static MATD::Buffer* Buffer(void* val, size_t size, size_t elem_size, buf_type argType = ARG_TYPE::DEVICE_READ | ARG_TYPE::HOST_WRITE);
			static MATD::Image* Image(void* val, size_t size, size_t elem_size, size_t width, size_t height, buf_type argType = ARG_TYPE::DEVICE_READ | ARG_TYPE::HOST_WRITE);
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