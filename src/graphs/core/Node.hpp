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
      virtual void UpdateParameters(MATD::JSON JSONObj) = 0;

      inline void AddInputSocket(std::string id, Ref<InputSocket> socket) { m_Inputs[id] = socket; };
			inline void AddOutputSocket(std::string id, Ref<OutputSocket> socket) { m_Outputs[id] = socket; };

			inline const MATD::JSON* GetJSON() { return &m_JSON; };
      inline void SetJSON(MATD::JSON JSONObj) { m_JSON = JSONObj; };

			inline const Ref<MATD::FUNC::Function>* GetFunction() { return &m_Function; };
			inline void SetFunction(Ref<MATD::FUNC::Function> function) { m_Function = function; };

      inline Ref<InputSocket> GetInputSocket(const std::string& id) { return m_Inputs[id]; };
      inline Ref<OutputSocket> GetOutputSocket(const std::string& id) { return m_Outputs[id]; };

      inline std::map <std::string, Ref<OutputSocket>> GetOutputSockets() { return m_Outputs; };
      inline std::map<std::string, Ref<InputSocket>> GetInputSockets() { return m_Inputs; };

			inline int GetID() { return m_ID; };
			inline Graph* GetGraph() { return m_Graph; };
      inline void SetID(int id) { m_ID = id; };

    private:
      int m_ID;
      Graph* m_Graph;
      MATD::JSON m_JSON;

      Ref<MATD::FUNC::Function> m_Function;
			std::map<std::string,Ref<InputSocket>> m_Inputs;
      std::map<std::string, Ref<OutputSocket>> m_Outputs;
    };
  }
}