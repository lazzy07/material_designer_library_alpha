#pragma once
#include <string>

namespace MATD {
	enum class DATA_TYPES {
		NUMBER1,
		NUMBER2,
		STRING,
		BOOLEAN,
		COLORVEC1,
		COLORVEC3,
		LUT1,
		LUT3
	};

	typedef float ColorVec1;
	typedef float Number1;
	
	struct ColorVec3 {
		float r;
		float g;
		float b;
	};


	struct Number2 {
		float x;
		float y;
	};

	struct Lut1 {
		ColorVec1* stops;
		size_t size;
	};

	struct Lut3 {
		ColorVec3* stops;
		size_t size;
	};
}