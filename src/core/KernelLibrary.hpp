#pragma once
#include <vector>
#include <map>
#include <string>
#include <filesystem>
#include "../engine/matd/Kernel.hpp"

namespace MATD{
  namespace CORE{
    class KernelLibrary {
    public:
      KernelLibrary();
      [[nodiscard]] const std::vector<std::string>& GetKernelLibPaths() const { return m_KernelLibPaths; };
      void AddKernelPath(const std::string& path) { m_KernelLibPaths.push_back(path); };
      void AddKernel(MATD::Kernel* kernel);

      MATD::Kernel* GetKernel(const std::string& kernelName);
    private:
      std::filesystem::path GetPath(const std::string& path, const std::string& fileName);
    private:
      std::vector<std::string> m_KernelLibPaths;
      std::map<std::string, MATD::Kernel*> m_Kernels;
    };
  }
}