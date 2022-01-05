#pragma once
#include <vector>
#include <string>

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

    typedef struct Argument {
      std::string key;
      DATA_TYPES dataType;
      void* data;
    };

    class Function{
    public:
      Function(MATD::GRAPH::Node* node);
      ~Function();

      virtual void Init() = 0;
      virtual void Calculate() = 0;
      virtual void Update() = 0;

      virtual void OnComplete() = 0;
      inline GRAPH::Node* GetNode() { return m_Node; };

    private:
      MATD::GRAPH::Node* m_Node;
      std::vector<Argument>m_Arguments;
    };
  }
}