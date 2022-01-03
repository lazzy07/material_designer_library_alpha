#pragma once
#include "Graph.hpp"
#include "../core/JSONParser.hpp"

namespace MATD{
  namespace GRAPH{
    class ShaderGraph : public Graph{
    public:
      ShaderGraph(MaterialGraph* graph, const MATD::JSON& JSONObj);
      ~ShaderGraph();

			virtual void Update(MATD::JSON JSONObj) override;
    };
  }
}