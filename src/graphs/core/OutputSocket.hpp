#pragma once
#include "Socket.hpp"

namespace MATD{
  namespace GRAPH{
    class OutputSocket : public Socket{
		public:
			OutputSocket(std::string id, Node* node, Ref<MATD::FUNC::Argument> argument);
			~OutputSocket();
			inline virtual Ref<Connection> GetConnection(const std::string& id) override { return m_Connections[id]; };
			inline virtual int NoOfConnections() override { return m_Connections.size(); };
		private:
			std::map<std::string, Ref<Connection>> m_Connections;
    };
  }
}