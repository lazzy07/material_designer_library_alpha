#include "OutputSocket.hpp"

MATD::GRAPH::OutputSocket::OutputSocket(std::string id, Node* node, Ref<MATD::FUNC::Argument> argument) : Socket(id, node, argument)
{
}

MATD::GRAPH::OutputSocket::~OutputSocket()
{
}
