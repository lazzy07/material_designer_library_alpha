#include "Argument.hpp"
#include "../../core/EngineManager.hpp"
#include "../../core/Core.hpp"
#include "../vendor/opencl/CLInt.hpp"
#include "../vendor/opencl/CLFloat.hpp"
#include "../vendor/opencl/CLImage.hpp"
#include "../vendor/opencl/CLBuffer.hpp"

namespace MATD {
	DTYPES::Argument::Argument(size_t id):m_ID(id) {
		
	}

	Int* MATD::Argument::Int(size_t id, int val)
	{
		CORE::SUPPORTED_ENGINES engine = CORE::EngineManager::GetSelectedEngine();

		switch (engine) {
		case CORE::SUPPORTED_ENGINES::CUDA:
			MATD_CORE_ASSERT(false, "ARGUMENT::CUDA not supported yet");
			break;
		case CORE::SUPPORTED_ENGINES::OPEN_CL:
			return new DTYPES::OPENCL::Int(id, val);
			break;

		}
		MATD_CORE_ASSERT(false, "ARGUMENT::Invalid engine selected");
		return nullptr;
	}

	Float* MATD::Argument::Float(size_t id, float val) {
		CORE::SUPPORTED_ENGINES engine = CORE::EngineManager::GetSelectedEngine();

		switch (engine) {
		case CORE::SUPPORTED_ENGINES::CUDA:
			MATD_CORE_ASSERT(false, "ARGUMENT::CUDA not supported yet");
			break;
		case CORE::SUPPORTED_ENGINES::OPEN_CL:
			return new DTYPES::OPENCL::Float(id, val);
			break;

		}
		MATD_CORE_ASSERT(false, "ARGUMENT::Invalid engine selected");
		return nullptr;
	}

	template<typename T>
	Image<T>* MATD::Argument::Image(size_t id, T* buffer, size_t size, size_t width, size_t height) {
		CORE::SUPPORTED_ENGINES engine = CORE::EngineManager::GetSelectedEngine();

		switch (engine) {
		case CORE::SUPPORTED_ENGINES::CUDA:
			MATD_CORE_ASSERT(false, "ARGUMENT::CUDA not supported yet");
			break;
		case CORE::SUPPORTED_ENGINES::OPEN_CL:
			return new DTYPES::OPENCL::Image<T>(id, buffer, size, width, height);
			break;

		}
		MATD_CORE_ASSERT(false, "ARGUMENT::Invalid engine selected");
		return nullptr;
	}

	template<typename T>
	Buffer<T>* MATD::Argument::Buffer(size_t id, T* buffer, size_t size) {
		CORE::SUPPORTED_ENGINES engine = CORE::EngineManager::GetSelectedEngine();

		switch (engine) {
		case CORE::SUPPORTED_ENGINES::CUDA:
			MATD_CORE_ASSERT(false, "ARGUMENT::CUDA not supported yet");
			break;
		case CORE::SUPPORTED_ENGINES::OPEN_CL:
			return new DTYPES::OPENCL::Buffer<T>(id, buffer, size);
			break;
		}
		MATD_CORE_ASSERT(false, "ARGUMENT::Invalid engine selected");
		return nullptr;
	}
}
