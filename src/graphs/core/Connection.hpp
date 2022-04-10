#pragma once
#include "../../core/Core.hpp"
#include "Socket.hpp"
#include "InputSocket.hpp"
#include "OutputSocket.hpp"

namespace MATD{
  namespace GRAPH{
    enum class CONNECTION_UPDATE_STATUS {
      UPDATED,
      IN_PROGRESS
    };

    class Connection{
    public:
      Connection(std::string id, Ref<MATD::GRAPH::InputSocket> input, Ref<MATD::GRAPH::OutputSocket> output);
      ~Connection();
      inline Ref<MATD::GRAPH::InputSocket> GetInput() { return m_Input; };
      inline Ref<MATD::GRAPH::OutputSocket> GetOutput() { return m_Output; };

      inline const std::string& GetID() { return m_ID; };

      void Update();
    private:
      std::string m_ID;

      Ref<MATD::GRAPH::InputSocket> m_Input;
      Ref<MATD::GRAPH::OutputSocket> m_Output;

      CONNECTION_UPDATE_STATUS m_UpdateStatus;
    };
  }
}