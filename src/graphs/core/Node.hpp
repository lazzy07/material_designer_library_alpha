#pragma once
#include "../../core/JSONParser.hpp"

namespace MATD{
  namespace GRAPH{
    class MaterialGraph;

    class Node{
    public:
      Node(MaterialGraph* graph, JSON JSONObj);
      ~Node();

      virtual void Update(MATD::JSON JSONObj) = 0;
      bool ShouldUpdate(MATD::JSON JSONObj);
    private:
      MaterialGraph* m_MaterialGraph;
      MATD::JSON m_JSON;
    };
  }
}