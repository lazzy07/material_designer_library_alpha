#pragma once
#include "Socket.hpp"

namespace MATD{
  namespace GRAPH{
    class InputSocket : public Socket{
    public:
      InputSocket(std::string id, Node* node, Ref<MATD::FUNC::Argument> argument);
			~InputSocket();
      inline virtual Ref<Connection> GetConnection(const std::string&) override { return m_Connection; };
			virtual void AddConnection(Ref<Connection> connection) override;
			virtual void RemoveConnection(const std::string& id) override;

      virtual int NoOfConnections() override;
			virtual Ref<FUNC::Argument> GetArgument() override;

			inline void Update() override;
    private:
			Ref<Connection> m_Connection = nullptr;
			Ref<MATD::FUNC::Argument> m_Argument;
    };
  }
}