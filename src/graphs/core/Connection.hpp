#pragma once
#include "../../core/Core.hpp"
#include "Socket.hpp"

namespace MATD{
  namespace GRAPH{
    class Connection{
    public:
      inline Ref<MATD::GRAPH::Socket> GetInput() { return m_Input; };
      inline Ref<MATD::GRAPH::Socket> GetOutput() { return m_Output; };

      inline bool GetUpdateStatus() { return m_IsUpdated; };
      inline void SetUpdateStatus(bool status) { m_IsUpdated = status; };

      inline const std::string& GetID() { return m_ID; };
    private:
      std::string m_ID;
      bool m_IsUpdated;

      Ref<MATD::GRAPH::Socket> m_Input;
      Ref<MATD::GRAPH::Socket> m_Output;
    };
  }
}