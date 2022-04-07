#pragma once 
#include <string>
#include "MatdDataTypes.hpp"
#include "../../engine/matd/Queue.hpp"

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

	enum class MAT_ARG {
		MAT_INTEGER						= (1 << 0),
		MAT_FLOAT							= (1 << 1),
		MAT_BUFFER						= (1 << 2),
		MAT_IMAGE							= (1 << 3),
		MAT_COLORVEC3					= (1 << 4),
		MAT_NUMBER2					  = (1 << 5),
	};


	class Int;
	class Float;
	class Buffer;
	class Image;
	class MatColorVec3;
	class MatNumber2;

	class WorkItem;

	class Argument {
		public:
			static MATD::Int* Int(int val);
			static MATD::Float* Float(float val);
			static MATD::MatColorVec3* ColorVec3(MATD::ColorVec3 val);
			static MATD::MatNumber2* Number2(MATD::Number2 val);
			static MATD::Buffer* Buffer(void* val, size_t size, size_t elem_size, buf_type argType);
			static MATD::Image* Image(void* val, size_t size, size_t elem_size, size_t width, size_t height, buf_type argType);
	};

	namespace DTYPES {
		class Argument {
		public:
			Argument(MAT_ARG type);
			~Argument();

			virtual void Bind(WorkItem* workItem, size_t index) = 0;
			virtual void Delete() = 0;
			virtual void AddToQueue(MATD::Queue* queue) = 0;

			inline bool IsBound() const { return m_IsBound; };
			inline void SeIsBound(bool bound) { m_IsBound = true; };
		private:
			MAT_ARG m_Type;
			bool m_IsBound = false;
		};
	}
}