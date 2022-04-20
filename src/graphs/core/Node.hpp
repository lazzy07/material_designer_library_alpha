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

      void AddInputSocket(const std::string& id, const Ref<InputSocket>& socket) { m_Inputs[id] = socket; }
			void AddOutputSocket(const std::string& id, const Ref<OutputSocket>& socket) { m_Outputs[id] = socket; }

			[[nodiscard]] const MATD::JSON* GetJSON() const { return &m_JSON; }
      void SetJSON(const MATD::JSON& JSONObj) { m_JSON = JSONObj; }

      [[nodiscard]] const Ref<MATD::FUNC::Function>* GetFunction() const { return &m_Function; }
			void SetFunction(const Ref<MATD::FUNC::Function>& function) { m_Function = function; }

      Ref<InputSocket> GetInputSocket(const std::string& id) { return m_Inputs[id]; }
      Ref<OutputSocket> GetOutputSocket(const std::string& id) { return m_Outputs[id]; }

      std::map <std::string, Ref<OutputSocket>> GetOutputSockets() { return m_Outputs; }
      std::map<std::string, Ref<InputSocket>> GetInputSockets() { return m_Inputs; }

      [[nodiscard]] int GetID() const { return m_ID; }
			[[nodiscard]] Graph* GetGraph() const { return m_Graph; }
      void SetID(const int& id) { m_ID = id; }

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