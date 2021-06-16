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
			private:
				cl::Kernel m_Kernel;
			};
		};
	};
};