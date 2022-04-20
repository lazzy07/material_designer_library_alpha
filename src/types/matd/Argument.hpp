#pragma once 
#include <string>
#include "MatdDataTypes.hpp"
#include "../../engine/matd/Queue.hpp"

#define buf_type int

namespace MATD {
	enum class MATD_TEXTURE_BIT_TYPE;

	namespace DTYPES
	{
		class Texture;
	}

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
		MAT_COLORVEC3					= (1 << 3),
		MAT_NUMBER2					  = (1 << 4),
		MAT_TEXGRAYSCALE			= (1 << 5),
		MAT_TEXCOLOR					= (1 << 6),
	};


	class Int;
	class Float;
	class Buffer;
	class ColorTexture;
	class GrayscaleTexture;
	class MatColorVec3;
	class MatNumber2;

	class WorkItem;

	class Argument {
		public:
			static MATD::Int* Int(int val);
			static MATD::Float* Float(float val);
			static MATD::MatColorVec3* ColorVec3(MATD::ColorVec3 val);
			static MATD::MatNumber2* Number2(MATD::Number2 val);
			static MATD::Buffer* Buffer(void* buffer, size_t size, size_t elem_size, buf_type argType);
			static MATD::ColorTexture* ColorTexture(MATD_TEXTURE_BIT_TYPE bitType, size_t width, size_t height, buf_type argType);
			static MATD::GrayscaleTexture* GrayscaleTexture(MATD_TEXTURE_BIT_TYPE bitType, size_t width, size_t height, buf_type argType);
	};

	namespace DTYPES {
		class Argument {
		public:
			Argument(MAT_ARG type);
			virtual ~Argument();

			virtual void Bind(WorkItem* workItem, size_t index) = 0;
			virtual void Delete() = 0;
			virtual void AddToQueue(MATD::Queue* queue) = 0;

			bool IsBound() const { return m_IsBound; }
			void SeIsBound(bool bound) { m_IsBound = true; }
		private:
			MAT_ARG m_Type;
			bool m_IsBound = false;
		};
	}
}