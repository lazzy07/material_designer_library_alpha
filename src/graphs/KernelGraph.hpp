#pragma once
#include "Graph.hpp"

namespace MATD{
  namespace GRAPH{
    class KernelGraph : public MATD::GRAPH::Graph{
      KernelGraph(const MATD::JSON& JSONObj);
      ~KernelGraph();
    };
  }
}