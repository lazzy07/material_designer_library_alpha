#pragma once
#include <vector>
#include <map>
#include <string>
#include <filesystem>
#include "../engine/Kernel.hpp"

namespace MATD{
  namespace CORE{
    class KernelLibrary {
    public:
      inline const std::vector<std::string>& GetKernelLibPaths() const { return m_KernelLibPaths; };
      inline void AddKernelPath(std::string path) { m_KernelLibPaths.push_back(path); };
      inline void AddKernel(MATD::Kernel* kernel);

      MATD::Kernel* GetKernel(const std::string& kernelName);
    private:
      std::filesystem::path GetPath(const std::string& path, const std::string& fileName);
    private:
      std::vector<std::string> m_KernelLibPaths;
      std::map<std::string, MATD::Kernel*> m_Kernels;
    };
  }
}