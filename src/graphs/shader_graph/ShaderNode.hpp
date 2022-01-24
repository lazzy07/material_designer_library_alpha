#pragma once
#include "../core/Node.hpp"

namespace MATD{
  namespace GRAPH{
    class ShaderNode : public Node{
    public:
      ShaderNode(Graph* graph, JSON JSONObj);
      ~ShaderNode();

      virtual void UpdateParameters(JSON JSONObj) override;
    };
  }
}