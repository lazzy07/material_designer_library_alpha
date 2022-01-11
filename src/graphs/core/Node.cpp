#include "Node.hpp"

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

MATD::Ref<MATD::GRAPH::Node> MATD::GRAPH::Node::GetInput(int id)
{
  for (auto element : m_Inputs) {
    if (element->GetID() == id) {
      return element;
    }
  }

  return nullptr;
}

MATD::Ref<MATD::GRAPH::Node> MATD::GRAPH::Node::GetOutput(int id)
{
  for (auto element : m_Outputs) {
    if (element->GetID() == id) {
      return element;
    }
  }

  return nullptr;
}
