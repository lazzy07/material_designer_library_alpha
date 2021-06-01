#include "CLKernel.hpp"
#include "../../../core/Core.hpp"

namespace MATD {
	namespace ENGINE {
		namespace OPENCL {
			void Kernel::CreateCLKernel() {
				std::string source = GetKernelData();
				size_t kernelLen = source.length();
				MATD_CORE_ASSERT(kernelLen, "CL_KERNEL::Invalid Kernel Found");

				cl::Program::Sources src(1, std::make_pair(source.c_str(), kernelLen));
				cl::Program program(, src);
			}
		}
	}
}