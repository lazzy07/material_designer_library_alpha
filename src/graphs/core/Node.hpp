#pragma once
#include "../../core/Core.hpp"
#include "../../core/JSONParser.hpp"
#include "../../functions/core/Function.hpp"

namespace MATD{
  namespace GRAPH{
    class MaterialGraph;

    class Node{
    public:
      Node(MaterialGraph* graph, JSON JSONObj);
      ~Node();

      virtual void Init() = 0;
      virtual void Update(MATD::JSON JSONObj) = 0;
      bool ShouldUpdate(MATD::JSON JSONObj);

			inline std::vector<Ref<Node>>* GetOutputs() { return &m_Outputs; };
			inline std::vector<Ref<Node>>* GetInputs() { return &m_Inputs; };

      Ref<Node> GetInput(int id);
			Ref<Node> GetOutput(int id);

      inline int GetID() { return m_ID; };
      inline int SetID(int id) { m_ID = id; };

    private:
      MaterialGraph* m_MaterialGraph;
      MATD::JSON m_JSON;
      int m_ID;

      Ref<MATD::FUNC::Function> m_Function;

			std::vector<Ref<Node>> m_Inputs;
			std::vector<Ref<Node>> m_Outputs;
    };
  }
}