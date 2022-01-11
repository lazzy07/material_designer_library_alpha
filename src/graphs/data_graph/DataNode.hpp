#pragma once
#include "../core/Node.hpp"

namespace MATD{
  namespace GRAPH{
    class DataNode : public Node{
    public:
      DataNode(Graph* graph, JSON JSONObj);
      ~DataNode();
			virtual void Init() override;
      virtual void Update(JSON JSONObj) override;
    };
  }
}