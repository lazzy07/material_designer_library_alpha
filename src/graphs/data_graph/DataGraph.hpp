#pragma once
#include "../core/Graph.hpp"

namespace MATD{
  namespace GRAPH{
    class DataGraph : public MATD::GRAPH::Graph{
    public:
      DataGraph(MaterialGraph* graph,const MATD::JSON& JSONObj);
      ~DataGraph();

			virtual void CreateNode(MATD::JSON JSONObj) override;
			virtual void RemoveNode(MATD::JSON JSONObj) override;
			virtual void AddConnection(MATD::JSON JSONObj) override;
			virtual void RemoveConnection(MATD::JSON JSONObj) override;
			virtual void Update(MATD::JSON JSONObj) override;
    };
  }
}