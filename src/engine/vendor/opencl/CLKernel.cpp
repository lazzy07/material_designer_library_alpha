#include "CLKernel.hpp"
#include "../../../core/Core.hpp"
#include "../../../core/EngineManager.hpp"
#include "CLDevice.hpp"
#include "CLPlatform.hpp"

namespace MATD {
	namespace ENGINE {
		namespace OPENCL {
			Kernel::Kernel(std::string id): MATD::Kernel(id) {
				
			}

			void Kernel::CreateCLKernel() {
				std::string source = GetKernelData();
				size_t kernelLen = source.length();
				MATD_CORE_ASSERT(kernelLen, "CL_KERNEL::Invalid Kernel Found");

				cl::Program::Sources src(1, std::make_pair(source.c_str(), kernelLen));
				Ref<ENGINE::Engine> engine = CORE::EngineManager::GetEngineInstance();
				Ref<ENGINE::OPENCL::Platform> platform = std::static_pointer_cast<ENGINE::OPENCL::Platform>(engine->GetSelectedPlatform());
				Ref<ENGINE::OPENCL::Device> device = std::static_pointer_cast<ENGINE::OPENCL::Device>(engine->GetSelectedDevice());

				cl::Program program(device->GetContext()->GetCLContext(), src);

				try {
					program.build(platform->GetCLDevices());
					m_Kernel = cl::Kernel(program, GetID().c_str());
				}
				catch (cl::Error error) {
					if (error.err() == CL_BUILD_PROGRAM_FAILURE) {
						for (cl::Device dev : platform->GetCLDevices()) {
							// Check the build status
							cl_build_status status = program.getBuildInfo<CL_PROGRAM_BUILD_STATUS>(dev);
							if (status != CL_BUILD_ERROR)
								continue;

							// Get the build log
							std::string name = dev.getInfo<CL_DEVICE_NAME>();
							std::string buildlog = program.getBuildInfo<CL_PROGRAM_BUILD_LOG>(dev);
							
							MATD_CORE_ERROR("For device: {} buildlog: \n{}", name, buildlog);
							MATD_CORE_ASSERT(false, "Build Failed");
						}
					}
				}
			}
		}
	}
}
