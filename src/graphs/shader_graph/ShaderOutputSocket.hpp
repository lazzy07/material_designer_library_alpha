#pragma once
#include "../core/OutputSocket.hpp"

namespace MATD::GRAPH
{
	class ShaderOutputSocket : public OutputSocket
	{
	public:
		ShaderOutputSocket(const std::string& id, Node* node);

		Ref<DTYPES::Texture> GetTexArgument();
		void SetTexArgument(const Ref<DTYPES::Texture>& texture) { m_TexArgument = texture; }
	private:
		Ref<DTYPES::Texture> m_TexArgument;
	};
}
