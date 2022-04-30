#include "CLTexture.hpp"
#include <CL/cl.hpp>

namespace MATD::DTYPES::OPENCL
{
	int Texture::NoOfChannelsToCLChannelTypes(const size_t noOfChannels)
	{
		switch (noOfChannels)
		{
		case 1:
			return CL_R;
		case 3:
			return CL_RGBA;
		default: ;
		}

		return CL_R;
	}


	int Texture::BitTypeToCLBitType(MATD::MATD_TEXTURE_BIT_TYPE bitType)
	{
		switch (bitType)
		{
		case MATD::MATD_TEXTURE_BIT_TYPE::TEX_8BIT:
			return CL_UNSIGNED_INT8;
		case MATD::MATD_TEXTURE_BIT_TYPE::TEX_16BIT:
			return CL_UNSIGNED_INT16;
		case MATD::MATD_TEXTURE_BIT_TYPE::TEX_32BIT:
			return CL_UNSIGNED_INT32;
		default: ;
		};

		return CL_UNSIGNED_INT8;
	}
}
