#include "ShaderOutputSocket.hpp"

MATD::GRAPH::ShaderOutputSocket::ShaderOutputSocket(const std::string& id, Node* node) : OutputSocket(id, node)
{

}

MATD::Ref<MATD::DTYPES::Texture> MATD::GRAPH::ShaderOutputSocket::GetTexArgument()
{
	return m_TexArgument;
}
