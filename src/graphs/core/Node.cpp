#include "Node.hpp"

MATD::GRAPH::Node::Node(MATD::GRAPH::MaterialGraph* graph, MATD::JSON JSONObj)
{
  m_JSON = JSONObj;
}

MATD::GRAPH::Node::~Node()
{
}

bool MATD::GRAPH::Node::ShouldUpdate(MATD::JSON JSONObj)
{
  if (JSONObj == m_JSON) {
    return false;
  }
  else {
    return true;
  }
}
