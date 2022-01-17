#pragma once
#include "Socket.hpp"

namespace MATD{
  namespace GRAPH{
    class InputSocket : public Socket{
    public:
      InputSocket(std::string id, Node* node, Ref<MATD::FUNC::Argument> argument);
			~InputSocket();
      inline virtual Ref<Connection> GetConnection(const std::string&) override { return m_Connection; };
      virtual int NoOfConnections() override;
			virtual Ref<FUNC::Argument> GetArgument() override;

    private:
			Ref<Connection> m_Connection;
			Ref<MATD::FUNC::Argument> m_Argument;
    };
  }
}