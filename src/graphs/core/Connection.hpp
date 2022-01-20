#pragma once
#include "../../core/Core.hpp"
#include "Socket.hpp"
#include "InputSocket.hpp"
#include "OutputSocket.hpp"

namespace MATD{
  namespace GRAPH{
    class Connection{
    public:
      Connection(const std::string& id, Ref<MATD::GRAPH::InputSocket> input, Ref<MATD::GRAPH::OutputSocket> output);
      ~Connection();
      inline Ref<MATD::GRAPH::InputSocket> GetInput() { return m_Input; };
      inline Ref<MATD::GRAPH::OutputSocket> GetOutput() { return m_Output; };

      inline const std::string& GetID() { return m_ID; };
    private:
      std::string m_ID;

      Ref<MATD::GRAPH::InputSocket> m_Input;
      Ref<MATD::GRAPH::OutputSocket> m_Output;
    };
  }
}