#pragma once
#include "../core/JSONParser.hpp"

namespace MATD{
  namespace GRAPH{
    class Node{
    public:
      Node(JSON JSONObj);
      ~Node();

      virtual void Update(MATD::JSON JSONObj) = 0;
      bool ShouldUpdate(MATD::JSON JSONObj);
    private:
      MATD::JSON m_JSON;
    };
  }
}