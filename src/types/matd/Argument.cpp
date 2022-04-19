#include "Argument.hpp"
#include "../../core/Core.hpp"
#include "../../core/EngineManager.hpp"
#include "../vendor/opencl/CLInt.hpp"
#include "../vendor/opencl/CLFloat.hpp"
#include "../vendor/opencl/CLImage.hpp"
#include "../vendor/opencl/CLBuffer.hpp"
#include "../vendor/opencl/CLColorVec3.hpp"
#include "../vendor/opencl/CLNumber2.hpp"

namespace MATD {
	DTYPES::Argument::Argument(MAT_ARG type): m_Type(type) {
		
	}

	DTYPES::Argument::~Argument() {
	}

	MATD::Int* MATD::Argument::Int(int val)
	{
		CORE::SUPPORTED_ENGINES engine = CORE::EngineManager::GetSelectedEngine();

		switch (engine) {
		case CORE::SUPPORTED_ENGINES::CUDA:
			MATD_CORE_ASSERT(false, "ARGUMENT::CUDA not supported yet");
			break;
		case CORE::SUPPORTED_ENGINES::OPEN_CL:
			return new DTYPES::OPENCL::Int(val);
			break;

		}
		MATD_CORE_ASSERT(false, "ARGUMENT::Invalid engine selected");
		return nullptr;
	}

	MATD::Float* MATD::Argument::Float(float val) {
		CORE::SUPPORTED_ENGINES engine = CORE::EngineManager::GetSelectedEngine();

		switch (engine) {
		case CORE::SUPPORTED_ENGINES::CUDA:
			MATD_CORE_ASSERT(false, "ARGUMENT::CUDA not supported yet");
			break;
		case CORE::SUPPORTED_ENGINES::OPEN_CL:
			return new DTYPES::OPENCL::Float(val);
			break;

		}
		MATD_CORE_ASSERT(false, "ARGUMENT::Invalid engine selected");
		return nullptr;
	}

	MATD::MatColorVec3* Argument::ColorVec3(MATD::ColorVec3 val)
	{
		CORE::SUPPORTED_ENGINES engine = CORE::EngineManager::GetSelectedEngine();

		switch (engine) {
		case CORE::SUPPORTED_ENGINES::CUDA:
			MATD_CORE_ASSERT(false, "ARGUMENT::CUDA not supported yet");
			break;
		case CORE::SUPPORTED_ENGINES::OPEN_CL:
			return new DTYPES::OPENCL::ColorVec3(val);
			break;
		}
		MATD_CORE_ASSERT(false, "ARGUMENT::Invalid engine selected");
		return nullptr;
	}

	MATD::MatNumber2* Argument::Number2(MATD::Number2 val)
	{
		CORE::SUPPORTED_ENGINES engine = CORE::EngineManager::GetSelectedEngine();

		switch (engine) {
		case CORE::SUPPORTED_ENGINES::CUDA:
			MATD_CORE_ASSERT(false, "ARGUMENT::CUDA not supported yet");
			break;
		case CORE::SUPPORTED_ENGINES::OPEN_CL:
			return new DTYPES::OPENCL::Number2(val);
			break;
		}
		MATD_CORE_ASSERT(false, "ARGUMENT::Invalid engine selected");
		return nullptr;
	}

	MATD::Image* MATD::Argument::Image(void* buffer, size_t size, size_t elem_size, size_t width, size_t height, buf_type argType, DTYPES::Texture* texture) {
		CORE::SUPPORTED_ENGINES engine = CORE::EngineManager::GetSelectedEngine();

		switch (engine) {
		case CORE::SUPPORTED_ENGINES::CUDA:
			MATD_CORE_ASSERT(false, "ARGUMENT::CUDA not supported yet");
			break;
		case CORE::SUPPORTED_ENGINES::OPEN_CL:
			return new DTYPES::OPENCL::Image(buffer, size, elem_size, width, height, argType);
		}
		MATD_CORE_ASSERT(false, "ARGUMENT::Invalid engine selected");
		return nullptr;
	}

	MATD::Buffer* MATD::Argument::Buffer(void* buffer, size_t size, size_t elem_size, buf_type argType) {
		CORE::SUPPORTED_ENGINES engine = CORE::EngineManager::GetSelectedEngine();

		switch (engine) {
		case CORE::SUPPORTED_ENGINES::CUDA:
			MATD_CORE_ASSERT(false, "ARGUMENT::CUDA not supported yet");
			break;
		case CORE::SUPPORTED_ENGINES::OPEN_CL:
			return new DTYPES::OPENCL::Buffer(buffer, size, elem_size, argType);
			break;
		}
		MATD_CORE_ASSERT(false, "ARGUMENT::Invalid engine selected");
		return nullptr;
	}
}

