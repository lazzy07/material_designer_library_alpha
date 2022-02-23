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

      void Compile();

      void SubmitToQueue(Ref<MATD::Queue> queue);
    private:
      std::string m_KernelSource;
      std::string m_FunctionsSource;
      std::map<std::string, Ref<MATD::FUNC::Argument>> m_DataArguments;
      Ref<MATD::Kernel> m_EngineKernel;
    private:
      //Binding variables coming from data graph
      void BindDataVariables(std::vector<MATD::Ref<MATD::GRAPH::Node>> dataOutputNodes);
			//Binding variables coming from shader graph (images)
      void BindShaderVariables(std::vector<MATD::Ref<MATD::GRAPH::Node>> shaderOutputNodes);
      //Creating the kernel source
      const std::string& CreateKernelString();
      //Initializing the engine kernel
      void InitKernel(const std::string& kernelSource);
      //Set outputs so that outputs can be ported to other graphs/nodes
      void SetOutputs();
    };
  }
}