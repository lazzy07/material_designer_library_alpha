#pragma once
#include <map>
#include <string>
#include "../../core/Core.hpp"
#include "../../core/JSONParser.hpp"

namespace MATD{
  namespace GRAPH {
    class Node;
  }

  namespace FUNC{
    enum class DATA_TYPES {
      _integer1,
      _float1,
      _string,
      _integer2,
      _float2,
      _color1,
      _color3,
      _lut1,
      _lut3
    };

    struct Argument {
      std::string id;
      DATA_TYPES dataType;
      void* data;
    };

    class Function{
    public:
			static Ref<FUNC::Function> FunctionFactory(int initialID);

      Function(MATD::GRAPH::Node* node);
      ~Function();

      virtual void Init(const MATD::JSON& JSONObj) = 0;
      virtual void Calculate() = 0;
      virtual void Update() = 0;

      virtual void OnComplete() = 0;

      inline GRAPH::Node* GetNode() { return m_Node; };
      inline std::map<std::string, Ref<Argument>>* GetArguments() { return &m_Arguments; };
      inline Ref<Argument> GetArgument(const std::string& id) { return m_Arguments.find(id)->second; };
      void SetArgument(std::string id, DATA_TYPES dataType, void* data);
    private:
      MATD::GRAPH::Node* m_Node;
      std::map<std::string, Ref<Argument>> m_Arguments;
    };
  }
}