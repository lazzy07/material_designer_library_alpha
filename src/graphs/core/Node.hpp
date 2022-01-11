#pragma once
#include "../../core/Core.hpp"
#include "../../core/JSONParser.hpp"
#include "../../functions/core/Function.hpp"

namespace MATD{
  namespace GRAPH{
    class Graph;

    class Node{
    public:

      Node(Graph* graph, JSON JSONObj);
      ~Node();

      virtual void Init() = 0;
      virtual void Update(MATD::JSON JSONObj) = 0;
      bool ShouldUpdate(MATD::JSON JSONObj);

			inline std::vector<Ref<Node>>* GetOutputs() { return &m_Outputs; };
			inline std::vector<Ref<Node>>* GetInputs() { return &m_Inputs; };
			inline const MATD::JSON* GetJSON() { return &m_JSON; };

			inline const Ref<MATD::FUNC::Function>* GetFunction() { return &m_Function; };
			inline void SetFunction(Ref<MATD::FUNC::Function> function) { m_Function = function; };

      Ref<Node> GetInput(int id);
			Ref<Node> GetOutput(int id);

      inline int GetID() { return m_ID; };
      inline void SetID(int id) { m_ID = id; };

    private:
      Graph* m_Graph;
      MATD::JSON m_JSON;
      int m_ID;

      Ref<MATD::FUNC::Function> m_Function;

			std::vector<Ref<Node>> m_Inputs;
			std::vector<Ref<Node>> m_Outputs;
    };
  }
}