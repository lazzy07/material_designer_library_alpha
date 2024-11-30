#pragma once

namespace MATD {
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