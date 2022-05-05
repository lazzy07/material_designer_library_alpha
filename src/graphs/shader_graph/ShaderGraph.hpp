#pragma once
#include "../core/Graph.hpp"
#include "../../core/JSONParser.hpp"

namespace MATD{
  namespace GRAPH{
    class ShaderGraph final : public MATD::GRAPH::Graph{
    public:
      ShaderGraph(MaterialGraph* graph, MATD::JSON JSONObj);
    	~ShaderGraph() override;

			virtual void CreateNode(MATD::JSON JSONObj) override;
			virtual void Update(MATD::JSON JSONObj) override;

      void RemoveNode(MATD::JSON JSONObj) override;
      void AddConnection(MATD::JSON JSONObj) override;
      void RemoveConnection(MATD::JSON JSONObj) override;

      virtual void Init(const MATD::JSON& JSONObj) override;
    };
  }
}