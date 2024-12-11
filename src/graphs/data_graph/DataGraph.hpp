#pragma once
#include "../core/Graph.hpp"
#include "DataNode.hpp"

namespace MATD{
  namespace GRAPH{
    /**
     * @brief DataGraph class that inherits from MATD::GRAPH::Graph, this class is used to store the data graph and update the data nodes.
     * Data nodes are special nodes that are used to store neumerical data that can be used in Kernel nodes and Shader nodes to perform operations on them.
     * 
     */
    class DataGraph final : public MATD::GRAPH::Graph{
    public:
      DataGraph(MaterialGraph* graph,const MATD::JSON& JSONObj);
      ~DataGraph() override;

			virtual void CreateNode(MATD::JSON JSONObj) override;
			virtual void Update(MATD::JSON JSONObj) override;
    };
  }
}