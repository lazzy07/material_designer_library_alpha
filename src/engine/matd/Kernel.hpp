#pragma once
#include <string>

namespace MATD {
	class Kernel {
	public:
		Kernel(std::string id);
		
		void LoadKernelDataFromFile(std::string const& path);
		void LoadKernelDataFromString(std::string const& kernel);
		inline const std::string& GetKernelData() const { return m_Source; };
		inline const std::string& GetID() const { return m_ID; };

		static Kernel* CreateKernel(std::string id);
	private:
		std::string m_Source;
		std::string m_ID;
	};
}