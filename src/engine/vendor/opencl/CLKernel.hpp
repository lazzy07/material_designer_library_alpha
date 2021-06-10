#pragma once
#include "../../matd/Kernel.hpp"
#include <CL/cl.hpp>

namespace MATD {
	namespace ENGINE {
		namespace OPENCL {
			class Kernel: public ENGINE::Kernel {
			public:
				void CreateCLKernel();
			private:
				cl::Kernel m_Kernel;
			};
		};
	};
};