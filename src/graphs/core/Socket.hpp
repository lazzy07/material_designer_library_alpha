#pragma once
#include "../../core/Core.hpp"
#include "../../functions/core/Argument.hpp"
#include "Node.hpp"
#include <string>

namespace MATD{
  namespace GRAPH{
    class Connection;

    class Socket{
    public:
      Socket(std::string id, Node* node);
      ~Socket();

      inline const std::string& GetID() { return m_ID; };
      inline Node* GetNode() { return m_Node; };
      virtual Ref<Connection> GetConnection(const std::string& id) = 0;
      virtual int NoOfConnections() = 0;
			virtual Ref<FUNC::Argument> GetArgument() = 0;
    private:
      std::string m_ID;
      Node* m_Node;
    };
  }
}