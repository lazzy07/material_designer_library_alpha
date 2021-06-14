#include "Kernel.hpp"
#include <iostream>
#include <fstream>

namespace MATD {
	namespace ENGINE {
		void Kernel::LoadKernelDataFromFile(std::string const& path){
			using BufIt = std::istreambuf_iterator<char>;
			std::ifstream in(path);
			m_Source = std::string(BufIt(in.rdbuf()), BufIt());
		}

		void Kernel::LoadKernelDataFromString(std::string const& kernel)
		{
			m_Source = kernel;
		}
	}
}