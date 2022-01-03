#pragma once
#include "../core/JSONParser.hpp"
#include <string>

namespace MATD {
  namespace GRAPH {
    class MaterialGraph;

    class Graph {
    public:
      Graph(MaterialGraph* graph, const MATD::JSON& JSONObj);
      ~Graph();

      inline const std::string& GetID() { return m_ID; };
      inline MaterialGraph* GetMaterialGraph() { return m_MaterialGraph; };

      virtual void Update(MATD::JSON JSONObj) = 0;
    private:
      std::string m_ID;
      MaterialGraph* m_MaterialGraph;
    private:
      void Init(const MATD::JSON& JSONObj);
    };
  };
};
