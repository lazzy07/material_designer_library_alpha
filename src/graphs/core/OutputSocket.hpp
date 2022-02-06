#pragma once
#include "Socket.hpp"
#include "../../functions/core/Argument.hpp"

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

			inline void SetUpdateStatus(bool status) { m_IsUpdated = status; };
			inline bool GetUpdateStatus() override { return m_IsUpdated; };
			inline void Update() override;

			virtual inline Ref<FUNC::Argument> GetArgument() override { return m_Argument; };
			inline void SetArgument(Ref<FUNC::Argument> arg) { m_Argument = arg; };
		private:
			std::map<std::string, Ref<Connection>> m_Connections;
			Ref<FUNC::Argument> m_Argument;
			bool m_IsUpdated;
    };
  }
}