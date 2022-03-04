#pragma once
#include "../core/Graph.hpp"
#include "../../engine/matd/Kernel.hpp"
#include "../../engine/matd/Queue.hpp"

namespace MATD{
  namespace GRAPH{
    class KernelGraph : public MATD::GRAPH::Graph{
    public:
      KernelGraph(MaterialGraph* graph, const MATD::JSON& JSONObj);
			~KernelGraph();

			virtual void CreateNode(MATD::JSON JSONObj) override;
			virtual void Update(MATD::JSON JSONObj) override;
      
      virtual void Init(const MATD::JSON& JSONObj) override;

			inline const std::string& GetKernelSource() { return m_KernelSource; };
			inline const std::string& GetFunctionsSource() { return m_FunctionsSource; };

      std::string Compile();

      void SubmitToQueue(Ref<MATD::Queue> queue);
      std::string GetKernelName();

    private:
      std::string m_KernelSource;
      std::string m_FunctionsSource;

      std::string m_ShaderSource;

      Ref<MATD::Kernel> m_EngineKernel;
    private:
      //Creating the kernel source
      void InitKernel();
      //Set outputs so that outputs can be ported to other graphs/nodes
      void SetOutputs();
    };
  }
}