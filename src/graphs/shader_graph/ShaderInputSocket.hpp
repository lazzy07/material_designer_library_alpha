#pragma once

#include "../core/InputSocket.hpp"
#include "../../types/matd/Texture.hpp"

namespace MATD::GRAPH
{
	class ShaderInputSocket : public InputSocket
	{
	public:
		ShaderInputSocket(const std::string& id, Node* node, const Ref<DTYPES::Texture>& texture);
		~ShaderInputSocket();

		Ref<DTYPES::Texture> GetTextureArgument();

	private:
		Ref<DTYPES::Texture> m_TexArgument;
	};
}
