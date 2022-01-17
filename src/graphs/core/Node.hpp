#pragma once
#include "../../core/Core.hpp"
#include "../../core/JSONParser.hpp"
#include "../../functions/core/Function.hpp"

namespace MATD{
  namespace GRAPH{
    class Graph;
    class InputSocket;
    class OutputSocket;

    class Node{
    public:

      Node(Graph* graph, JSON JSONObj);
      ~Node();

      virtual void Init() = 0;
      virtual void Update(MATD::JSON JSONObj) = 0;
      bool ShouldUpdate(MATD::JSON JSONObj);

			inline std::map<std::string, Ref<InputSocket>>* GetInputs() { return &m_Inputs; };
      inline void AddInputSocket(std::string id, Ref<InputSocket> socket) { m_Inputs[id] = socket; };
			inline void SetOutputSocket(std::string id, Ref<OutputSocket> socket) { m_Output = socket; };

			inline const MATD::JSON* GetJSON() { return &m_JSON; };

			inline const Ref<MATD::FUNC::Function>* GetFunction() { return &m_Function; };
			inline void SetFunction(Ref<MATD::FUNC::Function> function) { m_Function = function; };

      Ref<InputSocket> GetInput(const std::string& id);
			Ref<OutputSocket> GetOutput();

      inline int GetID() { return m_ID; };
      inline void SetID(int id) { m_ID = id; };

    private:
      int m_ID;
      Graph* m_Graph;
      MATD::JSON m_JSON;

      Ref<MATD::FUNC::Function> m_Function;
			std::map<std::string,Ref<InputSocket>> m_Inputs;
			Ref<OutputSocket> m_Output;
    };
  }
}