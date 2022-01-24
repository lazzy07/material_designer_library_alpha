#pragma once
#include "Socket.hpp"

namespace MATD{
  namespace GRAPH{
    class OutputSocket : public Socket{
		public:
			OutputSocket(std::string id, Node* node);
			~OutputSocket();
			inline virtual Ref<Connection> GetConnection(const std::string& id) override { return m_Connections[id]; };
			virtual void AddConnection(Ref<Connection> connection) override;
			virtual void RemoveConnection(const std::string& id) override;

			inline virtual int NoOfConnections() override { return m_Connections.size(); };
			virtual Ref<FUNC::Argument> GetArgument() override;

			inline void SetUpdateStatus(bool status) { m_IsUpdated = status; };
			inline bool GetUpdateStatus() override { return m_IsUpdated; };
			inline void Update() override;
		private:
			std::map<std::string, Ref<Connection>> m_Connections;
			bool m_IsUpdated;
    };
  }
}