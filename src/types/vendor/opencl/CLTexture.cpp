#include "CLTexture.hpp"
#include <CL/cl.hpp>
#include "../../../core/Log.hpp"
#include "../../../core/EngineManager.hpp"
#include "../../../engine/vendor/opencl/CLWorkItem.hpp"
#include "../../../engine/vendor/opencl/CLContext.hpp"
#include "../../../engine/vendor/opencl/CLDevice.hpp"
#include "../../../engine/vendor/opencl/CLQueue.hpp"

namespace MATD::DTYPES::OPENCL
{
	int Texture::NoOfChannelsToCLChannelTypes(const size_t noOfChannels)
	{
		switch (noOfChannels)
		{
		case 1:
			return CL_R;
		case 3:
			return CL_RGB;
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
