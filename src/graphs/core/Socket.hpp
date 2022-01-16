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
      Socket(std::string id, Node* node, Ref<MATD::FUNC::Argument> argument);
      ~Socket();

      inline const std::string& GetID() { return m_ID; };
      Ref<FUNC::Argument> GetArgument();
      virtual Ref<Connection> GetConnection(const std::string& id) = 0;
      virtual int NoOfConnections() = 0;
    private:
      std::string m_ID;
      Node* m_Node;
      Ref<MATD::FUNC::Argument> m_Argument;
    };
  }
}