#pragma once
#include "Graph.hpp"

namespace MATD{
  namespace GRAPH{
    class DataGraph : public MATD::GRAPH::Graph{
    public:
      DataGraph(const MATD::JSON& JSONObj);
      ~DataGraph();
    };
  }
}