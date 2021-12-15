#pragma once
#include "../core/Core.hpp"
#include "NodeGraph.hpp"

namespace MATD{
  namespace GRAPH {
    class JSONParser {
    public:
      Ref<NodeGraph> parseJSONToNodeGraph(const std::string& JSONString);
    private:

    };
  }
}