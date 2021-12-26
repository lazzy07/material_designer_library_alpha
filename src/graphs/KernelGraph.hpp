#pragma once
#include "Graph.hpp"

namespace MATD{
  namespace GRAPH{
    class KernelGraph : public MATD::GRAPH::Graph{
    public:
      KernelGraph(const MATD::JSON& JSONObj);
      ~KernelGraph();
    };
  }
}