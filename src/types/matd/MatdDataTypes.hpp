#pragma once
#include <string>
#include <vector>
#include "../../core/Core.hpp"

namespace MATD {
	enum class DATA_TYPES {
		NUMBER1,
		NUMBER2,
		STRING,
		BOOLEAN,
		COLORVEC1,
		COLORVEC3,
		LUT1,
		LUT3,
		TEXGRAYSCALE,
		TEXCOLOR
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

	struct Lut1Elem {
		ColorVec1 color;
		int pos;
	};

	struct Lut3Elem {
		ColorVec3 color;
		int pos;
	};

	struct Lut1 {
		Lut1Elem* stops;
		size_t length;
	};

	struct Lut3 {
		Lut3Elem* stops;
		size_t length;
	};
}