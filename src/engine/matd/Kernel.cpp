#include "Kernel.hpp"
#include <iostream>
#include <fstream>
#include "../../core/EngineManager.hpp"
#include "../vendor/opencl/CLKernel.hpp"

namespace MATD {
	Kernel::Kernel(std::string id): m_ID(id) {

	}

	void Kernel::LoadKernelDataFromFile(std::string const& path){
		using BufIt = std::istreambuf_iterator<char>;
		std::ifstream in(path);
		m_Source = std::string(BufIt(in.rdbuf()), BufIt());
	}

	void Kernel::LoadKernelDataFromString(std::string const& kernel)
	{
		m_Source = kernel;
	}

	Kernel* Kernel::CreateKernel(std::string id) {
		CORE::SUPPORTED_ENGINES engine = CORE::EngineManager::GetSelectedEngine();

		switch (engine) {
		case CORE::SUPPORTED_ENGINES::CUDA:
			MATD_CORE_ASSERT(false, "MAT_KERNEL::CUDA is not supported yet");
			break;
		case CORE::SUPPORTED_ENGINES::OPEN_CL:
			return new ENGINE::OPENCL::Kernel(id);
			break;
		}
		MATD_CORE_ASSERT(false, "MAT_KERNEL::Un-identified WorkItem type selected");
		return nullptr;

	}
}