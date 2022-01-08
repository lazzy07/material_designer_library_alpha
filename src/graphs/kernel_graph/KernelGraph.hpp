#pragma once
#include "../core/Graph.hpp"

namespace MATD{
  namespace GRAPH{
    class KernelGraph : public MATD::GRAPH::Graph{
    public:
      KernelGraph(MaterialGraph* graph, const MATD::JSON& JSONObj);
      ~KernelGraph();

			virtual void CreateNode(MATD::JSON JSONObj) override;
			virtual void RemoveNode(MATD::JSON JSONObj) override;
			virtual void AddConnection(MATD::JSON JSONObj) override;
			virtual void RemoveConnection(MATD::JSON JSONObj) override;
			virtual void Update(MATD::JSON JSONObj) override;
      
    };
  }
}