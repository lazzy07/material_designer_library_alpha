#pragma once
#include "../../core/Core.hpp"
#include "../../core/JSONParser.hpp"
#include "../../functions/core/Function.hpp"

namespace MATD{
  namespace GRAPH{
    class Graph;
    class Socket;

    class Node{
    public:

      Node(Graph* graph, JSON JSONObj);
      ~Node();

      virtual void Init() = 0;
      virtual void Update(MATD::JSON JSONObj) = 0;
      bool ShouldUpdate(MATD::JSON JSONObj);

			inline std::map<std::string, Ref<Socket>>* GetOutputs() { return &m_Output; };
			inline std::map<std::string, Ref<Socket>>* GetInputs() { return &m_Inputs; };
      inline void AddInputSocket(std::string id, Ref<Socket> socket) { m_Inputs[id] = socket; };
			inline void SetOutputSocket(std::string id, Ref<Socket> socket) { m_Output[id] = socket; };

			inline const MATD::JSON* GetJSON() { return &m_JSON; };

			inline const Ref<MATD::FUNC::Function>* GetFunction() { return &m_Function; };
			inline void SetFunction(Ref<MATD::FUNC::Function> function) { m_Function = function; };

      Ref<Socket> GetInput(const std::string& id);
			Ref<Socket> GetOutput();

      inline int GetID() { return m_ID; };
      inline void SetID(int id) { m_ID = id; };

    private:
      int m_ID;
      Graph* m_Graph;
      MATD::JSON m_JSON;

      Ref<MATD::FUNC::Function> m_Function;
			std::map<std::string,Ref<Socket>> m_Inputs;
			Ref<Socket> m_Output;
    };
  }
}