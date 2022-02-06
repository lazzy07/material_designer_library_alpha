#pragma once
#include <map>
#include <string>
#include "../../core/Core.hpp"
#include "../../core/JSONParser.hpp"
#include "../../types/matd/MatdDataTypes.hpp"
#include "Argument.hpp"

namespace MATD{
  namespace GRAPH {
    class Node;
  }

  namespace FUNC{
    class Function{
    public:

      Function(MATD::GRAPH::Node* node);
      ~Function();

      virtual void Init(MATD::JSON JSONObj) = 0;
      virtual void Calculate() = 0;
      void Update();
      void OnComplete();

      inline GRAPH::Node* GetNode() { return m_Node; };
      void SetArgument(Ref<Argument> arg);
      inline Ref<Argument> GetArgument(const std::string& id) { return m_Arguments[id]; };

      inline std::map<std::string, Ref<Argument>> GetArguments() { return m_Arguments; };
    private:
      MATD::GRAPH::Node* m_Node;

      //Arguments are the node properties coming from Material Designer editor
      std::map<std::string, Ref<Argument>> m_Arguments;
    };
  }
}