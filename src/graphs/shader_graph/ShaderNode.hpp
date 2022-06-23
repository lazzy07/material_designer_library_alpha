#pragma once
#include "../core/Node.hpp"

namespace MATD{
  namespace GRAPH{
    class ShaderNode : public Node{
    public:
      ShaderNode(Graph* graph, JSON JSONObj);
      ~ShaderNode();

			void Init() override;
      void UpdateParameters(JSON JSONObj, int subNodeId = -1) override;

      void SetDisplayTexture(const Ref<DTYPES::Texture>& texture) { m_DisplayTexture = texture; }
      [[nodiscard]] Ref<DTYPES::Texture> GetDisplayTexture() const { return m_DisplayTexture; }
    private:
      Ref<DTYPES::Texture> m_DisplayTexture;
    };
  }
}