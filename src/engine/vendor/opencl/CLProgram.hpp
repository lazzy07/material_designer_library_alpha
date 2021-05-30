#pragma once
#include <cl/cl.hpp>
#include "CLKernel.hpp"
namespace MATD {
	namespace ENGINE {
		namespace OPENCL {
			class Program {
			public:
				void LoadKernel();
			private:
				cl::Program m_Program;
				OPENCL::Kernel m_Kernel;
			};
		};
	};
}