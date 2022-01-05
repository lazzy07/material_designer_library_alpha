#pragma once
#include "../core/Node.hpp"

namespace MATD{
  namespace GRAPH{
    class DataNode : public Node{
    public:
      DataNode(MaterialGraph* graph, JSON JSONObj);
      ~DataNode();

      virtual void Update(JSON JSONObj) override;
    };
  }
}