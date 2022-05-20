#pragma once
#include <map>
#include <string>
#include "../../core/Core.hpp"
#include "../../core/JSONParser.hpp"
#include "Argument.hpp"

namespace MATD{
  namespace GRAPH {
    class Node;
  }

  namespace FUNC{
    enum class FUNCTION_TYPE {
      OUTPUT,
      INPUT,
      PROCESS,
    };

    class Function{
    public:

      Function(MATD::GRAPH::Node* node);
      ~Function();

      virtual void Init(MATD::JSON JSONObj) = 0;
      virtual void Calculate() = 0;
      virtual void Update();
      virtual void OnComplete();

      void SetArgument(Ref<Argument> arg);

      [[nodiscard]] GRAPH::Node* GetNode() const { return m_Node; }
      Ref<Argument> GetArgument(const std::string& id) { return m_Arguments[id]; }

      std::map<std::string, Ref<Argument>> GetArguments() { return m_Arguments; }

      [[nodiscard]] FUNCTION_TYPE GetFunctionType() const { return m_FunctionType; }
      void SetFunctionType(FUNCTION_TYPE functionType) { m_FunctionType = functionType; }
      
    private:
      MATD::GRAPH::Node* m_Node;
      MATD::FUNC::FUNCTION_TYPE m_FunctionType;
      //Arguments are the node properties coming from Material Designer editor
      std::map<std::string, Ref<Argument>> m_Arguments;
    };
  }
}