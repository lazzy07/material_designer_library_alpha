#pragma once
#include "../core/Graph.hpp"
#include "../../core/JSONParser.hpp"
#include "ShaderNode.hpp"

namespace MATD{
  namespace GRAPH{
    class ShaderGraph : public Graph{
    public:
      ShaderGraph(MaterialGraph* graph, const MATD::JSON& JSONObj);
      ~ShaderGraph();

			virtual void CreateNode(MATD::JSON JSONObj) override;
			virtual void RemoveNode(MATD::JSON JSONObj) override;
			virtual void AddConnection(MATD::JSON JSONObj) override;
			virtual void RemoveConnection(MATD::JSON JSONObj) override;
			virtual void Update(MATD::JSON JSONObj) override;

			inline std::map<int, Ref<MATD::GRAPH::ShaderNode>>* GetNodes() { return &m_Nodes; };
			inline Ref<MATD::GRAPH::ShaderNode> GetNode(int id) { return m_Nodes[id]; };
		private:
			std::map<int, Ref<MATD::GRAPH::ShaderNode>> m_Nodes;
    };
  }
}