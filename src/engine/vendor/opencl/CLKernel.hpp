#pragma once
#include "../../matd/Kernel.hpp"
#include <CL/cl.hpp>
#include <string>

namespace MATD {
	namespace ENGINE {
		namespace OPENCL {
			class Kernel: public MATD::Kernel {
			public:
				Kernel(std::string id);
				void CreateCLKernel();
				inline const cl::Kernel& GetCLKernel() const { return m_Kernel; };
			private:
				cl::Kernel m_Kernel;
			};
		};
	};
};