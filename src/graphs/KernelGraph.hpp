#pragma once
#include "Graph.hpp"

namespace MATD{
  namespace GRAPH{
    class KernelGraph : public MATD::GRAPH::Graph{
    public:
      KernelGraph(MaterialGraph* graph, const MATD::JSON& JSONObj);
      ~KernelGraph();

			virtual void Update(MATD::JSON JSONObj) override;
    };
  }
}