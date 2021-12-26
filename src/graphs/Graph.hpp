#pragma once
#include "../core/JSONParser.hpp"
#include <string>

namespace MATD {
  namespace GRAPH {
    enum class NODE_IO_TYPE {
      OUTPUT,
      GENERATOR,
      PROCESS
    };

    class Graph {
    public:
      Graph(const MATD::JSON& jsonObj);
      ~Graph();

      inline const std::string& const GetID() { return m_ID; };
      inline NODE_IO_TYPE const GetIOType() { return m_IOType; };
    private:
      std::string m_ID;
      NODE_IO_TYPE m_IOType;

    private:
      void Init(const MATD::JSON& jsonObj);
    };
  };
};
