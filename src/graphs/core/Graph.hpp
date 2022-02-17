#pragma once
#include "../../core/JSONParser.hpp"
#include "../../core/Core.hpp"
#include "Connection.hpp"
#include <string>

namespace MATD {
  namespace GRAPH {
    class MaterialGraph;
    class Node;

    class Graph {
    public:
      Graph(MaterialGraph* graph, const MATD::JSON& JSONObj);
      ~Graph();

      inline const std::string& GetID() { return m_ID; };
      inline MaterialGraph* GetMaterialGraph() { return m_MaterialGraph; };

			virtual void CreateNode(MATD::JSON JSONObj) = 0;
			void RemoveNode(MATD::JSON JSONObj);
			void AddConnection(MATD::JSON JSONObj);
			void RemoveConnection(MATD::JSON JSONObj);
			virtual void Update(MATD::JSON JSONObj) = 0;
      virtual void Init(const MATD::JSON& JSONObj) = 0;

			inline std::map<int, Ref<MATD::GRAPH::Node>>* GetNodes() { return &m_Nodes; };
			inline Ref<MATD::GRAPH::Node> GetNode(int id) { return m_Nodes[id]; };
      inline void SetNode(int id, Ref<Node> node) { m_Nodes[id] = node; };
			
      inline std::map<std::string, Ref<MATD::GRAPH::Connection>>* GetConnections() { return &m_Connections; };
      inline Ref<MATD::GRAPH::Connection> GetConnection(const std::string& id) { return m_Connections[id]; };
			inline void AddToConnectionPool(std::string id, Ref<Connection> connection) { m_Connections[id] = connection; };
			inline void RemoveFromConnectionPool(std::string id) { m_Connections.erase(id); };
      inline void SetID(std::string id) { m_ID = id; };
			

    private:
      std::string m_ID;
      MaterialGraph* m_MaterialGraph;
			std::map<int, Ref<MATD::GRAPH::Node>> m_Nodes;
      std::map<std::string, Ref<MATD::GRAPH::Connection>> m_Connections;
    };
  };
};
