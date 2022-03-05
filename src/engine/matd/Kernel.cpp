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

	Kernel* Kernel::CreateKernelFromFile(std::string id, std::string const& path) {
		CORE::SUPPORTED_ENGINES engine = CORE::EngineManager::GetSelectedEngine();

		switch (engine) {
		case CORE::SUPPORTED_ENGINES::CUDA:
			MATD_CORE_ASSERT(false, "MAT_KERNEL::CUDA is not supported yet");
			break;
		case CORE::SUPPORTED_ENGINES::OPEN_CL:
			ENGINE::OPENCL::Kernel* kernel = new ENGINE::OPENCL::Kernel(id);
			kernel->LoadKernelDataFromFile(path);
			kernel->CreateCLKernel();
			return kernel;
			break;
		}
		MATD_CORE_ASSERT(false, "MAT_KERNEL::Un-identified WorkItem type selected");
		return nullptr;
	}

	Kernel* Kernel::CreateKernelFromSource(std::string id, std::string const& source, std::string* error) {
		CORE::SUPPORTED_ENGINES engine = CORE::EngineManager::GetSelectedEngine();

		switch (engine) {
		case CORE::SUPPORTED_ENGINES::CUDA:
			MATD_CORE_ASSERT(false, "MAT_KERNEL::CUDA is not supported yet");
			break;
		case CORE::SUPPORTED_ENGINES::OPEN_CL:
			ENGINE::OPENCL::Kernel* kernel = new ENGINE::OPENCL::Kernel(id);
			kernel->LoadKernelDataFromString(source);
			std::string err = kernel->CreateCLKernel();

			if (err.size() > 0) {
				//Has an error
				*error = err;
			}

			return kernel;
			break;
		}
		MATD_CORE_ASSERT(false, "MAT_KERNEL::Un-identified WorkItem type selected");
		return nullptr;
	}
}