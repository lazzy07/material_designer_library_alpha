#include "CLKernel.hpp"
#include "../../../core/Core.hpp"
#include "../../../core/EngineManager.hpp"
#include "CLDevice.hpp"
#include "CLPlatform.hpp"

namespace MATD {
	namespace ENGINE {
		namespace OPENCL {
			void Kernel::CreateCLKernel() {
				std::string source = GetKernelData();
				size_t kernelLen = source.length();
				MATD_CORE_ASSERT(kernelLen, "CL_KERNEL::Invalid Kernel Found");

				cl::Program::Sources src(1, std::make_pair(source.c_str(), kernelLen));
				Ref<ENGINE::Engine> engine = CORE::EngineManager::GetEngineInstance();
				Ref<ENGINE::OPENCL::Platform> platform = std::static_pointer_cast<ENGINE::OPENCL::Platform>(engine->GetSelectedPlatform());
				Ref<ENGINE::OPENCL::Device> device = std::static_pointer_cast<ENGINE::OPENCL::Device>(engine->GetSelectedDevice());
				
				cl::Program program(device->GetContext()->GetContext(), src);

				program.build(platform->GetCLDevices());
			}
		}
	}
}
