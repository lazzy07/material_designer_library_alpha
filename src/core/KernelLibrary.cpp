#include "KernelLibrary.hpp"
#include "EngineManager.hpp"
#include "Log.hpp"

namespace MATD {
	namespace CORE {
		KernelLibrary::KernelLibrary()
		{
			MATD_CORE_TRACE("MATD_KERNEL_LIB::Initialized");
		}

		inline void KernelLibrary::AddKernel(MATD::Kernel* kernel)
		{
			if(m_Kernels.find(kernel->GetID()) == m_Kernels.end()) {
				m_Kernels.insert(std::pair<std::string, Kernel*>(kernel->GetID(), kernel));
			} else {
				MATD_CORE_WARN("Kernel with the name of {} is already been loaded", kernel->GetID());
			}
		}

		MATD::Kernel* KernelLibrary::GetKernel(const std::string& kernelName)
		{
			
			if (m_Kernels.find(kernelName) == m_Kernels.end()) {
				for (std::string path : m_KernelLibPaths) {
					std::filesystem::path file = GetPath(path, kernelName);
					bool exists = std::filesystem::exists(file);
					if (exists) {
						MATD::Kernel* kernel = Kernel::CreateKernelFromFile(kernelName, file.u8string());
						MATD_CORE_INFO("KERNEL_LIB:::Kernel loaded from file id: {}", kernel->GetID());
						AddKernel(kernel);
						return kernel;
					};
				}
				return nullptr;
			} else {
				auto itr = m_Kernels.find(kernelName);

				if (itr != m_Kernels.end()) {
					MATD_CORE_INFO("KERNEL_LIB::Kernel loaded from memory id: {}", itr->second->GetID());
					return itr->second;
				}
			}
			return nullptr;
		}

		std::filesystem::path KernelLibrary::GetPath(const std::string& path, const std::string& fileName)
		{
			MATD::CORE::SUPPORTED_ENGINES type = MATD::CORE::EngineManager::GetSelectedEngine();
			std::string ext = "";
			std::string folder = "";
			
			switch (type)
			{
			case MATD::CORE::SUPPORTED_ENGINES::OPEN_CL:
				folder = "/cl/";
				ext = ".cl";
				break;
			case MATD::CORE::SUPPORTED_ENGINES::CUDA:
				folder = "/cuda/";
				ext = ".cu";
				MATD_CORE_ASSERT(false, "CUDA is not supported yet");
				break;
			default:
				MATD_CORE_ASSERT(false, "Unknown engine type found!");
				break;
			}
			std::filesystem::path dir(path);
			dir += folder;
			dir += fileName + ext;
			return dir;
		}
	}
}