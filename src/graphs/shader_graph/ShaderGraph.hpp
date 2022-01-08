#pragma once
#include "../core/Graph.hpp"
#include "../../core/JSONParser.hpp"

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
    };
  }
}