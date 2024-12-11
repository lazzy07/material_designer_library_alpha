/**
 * @file KernelLibrary.hpp
 * @author Lasantha M Senanayake (222lasantha@gmail.com)
 * @brief Kernel library class, which is used to store and manage kernels
 * @version 0.1
 * @date 2024-11-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once
#include <vector>
#include <map>
#include <string>
#include <filesystem>
#include "../engine/matd/Kernel.hpp"

namespace MATD{
  namespace CORE{
    /**
     * @brief Kernel Library class, which is used to store and manage kernels
     * 
     */
    class KernelLibrary {
    public:
      KernelLibrary();
      /**
       * @brief Get the Kernel Lib Paths object which is a list of paths to search for kernel files.
       * 
       * @return const std::vector<std::string>& List of paths, which are used to search for kernel files.
       */
      [[nodiscard]] const std::vector<std::string>& GetKernelLibPaths() const { return m_KernelLibPaths; };

      /**
       * @brief Add a path to the kernel library paths
       * 
       * @param path Path to add to the kernel library paths
       */
      void AddKernelPath(const std::string& path) { m_KernelLibPaths.push_back(path); };
      
      /**
       * @brief Add a kernel to the kernel library
       * 
       * @param kernel Kernel to add to the kernel library
       */
      void AddKernel(MATD::Kernel* kernel);

      /**
       * @brief Get the Kernel object
       * 
       * @param kernelName Name of the kernel to get
       * @return MATD::Kernel* Kernel object
       */
      MATD::Kernel* GetKernel(const std::string& kernelName);
    private:
      /**
       * @brief Get the Path object
       * 
       * @param path Path to search for the file
       * @param fileName Name of the file to search
       * @return std::filesystem::path Path to the file
       */
      std::filesystem::path GetPath(const std::string& path, const std::string& fileName);
    private:
      // List of paths to search for kernel files
      std::vector<std::string> m_KernelLibPaths;
      // Map of kernels
      std::map<std::string, MATD::Kernel*> m_Kernels;
    };
  }
}