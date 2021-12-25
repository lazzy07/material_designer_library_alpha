#pragma once
#include "Graph.hpp"
#include "../core/JSONParser.hpp"

namespace MATD{
  namespace GRAPH{
    class ShaderGraph : public Graph{
    public:
      ShaderGraph(const MATD::JSON& JSONObj);
      ~ShaderGraph();
    };
  }
}