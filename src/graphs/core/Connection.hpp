#pragma once
#include "../../core/Core.hpp"
#include "Socket.hpp"

namespace MATD{
  namespace GRAPH{
    class Connection{
    public:
      inline Ref<MATD::GRAPH::Socket> GetInput() { return m_Input; };
      inline Ref<MATD::GRAPH::Socket> GetOutput() { return m_Output; };

      inline const std::string& GetID() { return m_ID; };
    private:
      std::string m_ID;

      Ref<MATD::GRAPH::Socket> m_Input;
      Ref<MATD::GRAPH::Socket> m_Output;
    };
  }
}