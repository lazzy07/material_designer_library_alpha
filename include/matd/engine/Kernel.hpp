#pragma once
#include <string>

namespace MATD {
	class Kernel {
	public:
		Kernel(std::string id);
		
		void LoadKernelDataFromFile(std::string const& path);
		void LoadKernelDataFromString(std::string const& kernel);
		inline const std::string& GetKernelData() const { return m_Source; };
		inline std::string GetID() const { return m_ID; };

		static Kernel* CreateKernelFromFile(std::string id, std::string const& path);
		static Kernel* CreateKernelFromSource(std::string id, std::string const& kernel, std::string* error);
	private:
		std::string m_Source;
		std::string m_ID;
	};
}