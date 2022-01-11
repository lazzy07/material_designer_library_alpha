#pragma once
#include "../core/Graph.hpp"
#include "DataNode.hpp"

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

			inline std::map<int, Ref<MATD::GRAPH::DataNode>>* GetNodes() { return &m_Nodes; };
			inline Ref<MATD::GRAPH::DataNode> GetNode(int id) { return m_Nodes[id]; };
		private:
			std::map<int, Ref<MATD::GRAPH::DataNode>> m_Nodes;
    };
  }
}