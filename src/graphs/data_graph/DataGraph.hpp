#pragma once
#include "../core/Graph.hpp"

namespace MATD{
  namespace GRAPH{
    class DataGraph : public MATD::GRAPH::Graph{
    public:
      DataGraph(MaterialGraph* graph,const MATD::JSON& JSONObj);
      ~DataGraph();
      virtual void Update(MATD::JSON JSONObj) override;
    };
  }
}