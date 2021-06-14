#pragma once
#include <string>

namespace MATD {
	namespace ENGINE {
		class Kernel {
		public:
			void LoadKernelDataFromFile(std::string const& path);
			void LoadKernelDataFromString(std::string const& kernel);
			const std::string& GetKernelData() const { return m_Source; };
		private:
			std::string m_Source;
		};
	}
}