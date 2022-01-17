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

bool MATD::GRAPH::Node::ShouldUpdate(MATD::JSON JSONObj)
{
  if (JSONObj == m_JSON) {
    return false;
  }
  else {
    return true;
  }
}

MATD::Ref<MATD::GRAPH::InputSocket> MATD::GRAPH::Node::GetInput(const std::string& id)
{
  return m_Inputs[id];
}

MATD::Ref<MATD::GRAPH::OutputSocket> MATD::GRAPH::Node::GetOutput()
{
  return m_Output;
}
