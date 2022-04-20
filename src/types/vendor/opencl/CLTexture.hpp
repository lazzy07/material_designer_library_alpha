#pragma once
#include "../../../types/matd/Texture.hpp"

namespace MATD {
	namespace DTYPES {
		namespace OPENCL {
			class Texture {
			public:
				static int NoOfChannelsToCLChannelTypes(size_t noOfChannels);
				static int BitTypeToCLBitType(MATD::MATD_TEXTURE_BIT_TYPE bitType);
			};
		}
	}
}