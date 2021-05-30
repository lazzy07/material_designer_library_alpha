#pragma once
#include <string>

namespace MATD {
	namespace ENGINE {
		class Kernel {
			void LoadKernelDataFromFile(std::string const& path);
			const std::string& GetKernelData() const { return m_Source; };
		private:
			std::string m_Source;
		};
	}
}