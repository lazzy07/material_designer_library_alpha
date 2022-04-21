#include "ShaderInputSocket.hpp"
#include "../core/Connection.hpp"
#include "ShaderOutputSocket.hpp"

MATD::GRAPH::ShaderInputSocket::ShaderInputSocket(const std::string& id, Node* node, const Ref<DTYPES::Texture>& texture) : InputSocket(id, node, nullptr), m_TexArgument(texture)
{

}

MATD::GRAPH::ShaderInputSocket::~ShaderInputSocket()
{
}

MATD::Ref<MATD::DTYPES::Texture> MATD::GRAPH::ShaderInputSocket::GetTextureArgument()
{
	if (this->NoOfConnections() > 0) {
		if (const auto output = GetConnection("")->GetOutput()) {
			auto out = (ShaderOutputSocket*)output.get();
			return out->GetTexArgument();
		}
	}

	return this->m_TexArgument;
}
