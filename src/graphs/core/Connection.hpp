#pragma once
#include "../../core/Core.hpp"
#include "Socket.hpp"
#include "InputSocket.hpp"
#include "OutputSocket.hpp"
#include "../../core/Time.hpp"

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

      inline void SetUpdateStatus(CONNECTION_UPDATE_STATUS status, uint64_t time) { 
        m_UpdatedTime = time; 
        m_UpdateStatus = status; 
      };

      inline CONNECTION_UPDATE_STATUS GetUpdateStatus() const { return m_UpdateStatus; };
      inline const std::string& GetID() { return m_ID; };

      void Update(uint64_t time);
    private:
      std::string m_ID;

      uint64_t m_UpdatedTime = 0;
      CONNECTION_UPDATE_STATUS m_UpdateStatus;

      Ref<MATD::GRAPH::InputSocket> m_Input;
      Ref<MATD::GRAPH::OutputSocket> m_Output;

    };
  }
}