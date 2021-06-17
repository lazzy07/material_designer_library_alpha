#include "Argument.hpp"
#include "../../core/EngineManager.hpp"
#include "../../core/Core.hpp"
#include "../vendor/opencl/CLInt.hpp"
#include "../vendor/opencl/CLFloat.hpp"
#include "../vendor/opencl/CLImage.hpp"
#include "../vendor/opencl/CLBuffer.hpp"

namespace MATD {
	DTYPES::Argument::Argument() {
		
	}

	Int* MATD::Argument::Int(int val)
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

	Float* MATD::Argument::Float(float val) {
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

	template<typename T>
	Image<T>* MATD::Argument::Image(T* buffer, size_t size, size_t width, size_t height) {
		CORE::SUPPORTED_ENGINES engine = CORE::EngineManager::GetSelectedEngine();

		switch (engine) {
		case CORE::SUPPORTED_ENGINES::CUDA:
			MATD_CORE_ASSERT(false, "ARGUMENT::CUDA not supported yet");
			break;
		case CORE::SUPPORTED_ENGINES::OPEN_CL:
			return new DTYPES::OPENCL::Image<T>(buffer, size, width, height);
			break;

		}
		MATD_CORE_ASSERT(false, "ARGUMENT::Invalid engine selected");
		return nullptr;
	}

	template<typename T>
	Buffer<T>* MATD::Argument::Buffer(T* buffer, size_t size) {
		CORE::SUPPORTED_ENGINES engine = CORE::EngineManager::GetSelectedEngine();

		switch (engine) {
		case CORE::SUPPORTED_ENGINES::CUDA:
			MATD_CORE_ASSERT(false, "ARGUMENT::CUDA not supported yet");
			break;
		case CORE::SUPPORTED_ENGINES::OPEN_CL:
			return new DTYPES::OPENCL::Buffer<T>(buffer, size);
			break;
		}
		MATD_CORE_ASSERT(false, "ARGUMENT::Invalid engine selected");
		return nullptr;
	}
}
