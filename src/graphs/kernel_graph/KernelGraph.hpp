#pragma once
#include "../core/Graph.hpp"

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
    private:
      std::string m_KernelSource;
      std::string m_FunctionsSource;
    };
  }
}