#pragma once
#include "Socket.hpp"

namespace MATD{
  namespace GRAPH{
    class OutputSocket : public Socket{
		public:
			OutputSocket(std::string id, Node* node);
			~OutputSocket();
			inline virtual Ref<Connection> GetConnection(const std::string& id) override { return m_Connections[id]; };
			inline virtual int NoOfConnections() override { return m_Connections.size(); };
			virtual Ref<FUNC::Argument> GetArgument() override;

		private:
			std::map<std::string, Ref<Connection>> m_Connections;
    };
  }
}