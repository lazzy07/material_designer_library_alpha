#pragma once
#include "../core/Graph.hpp"
#include "DataNode.hpp"

namespace MATD{
  namespace GRAPH{
    class DataGraph final : public MATD::GRAPH::Graph{
    public:
      DataGraph(MaterialGraph* graph,const MATD::JSON& JSONObj);
      ~DataGraph() override;

			virtual void CreateNode(MATD::JSON JSONObj) override;
			virtual void Update(MATD::JSON JSONObj) override;
    };
  }
}