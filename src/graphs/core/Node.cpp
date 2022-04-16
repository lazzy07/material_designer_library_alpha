#include "Node.hpp"
#include "Socket.hpp"

MATD::GRAPH::Node::Node(MATD::GRAPH::Graph* graph, MATD::JSON JSONObj)
{
  m_JSON = JSONObj;
  this->SetID(m_JSON["id"].get<int>());
}

MATD::GRAPH::Node::~Node()
{
}