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
      virtual ~Graph();

      std::string GetID() { return m_ID; };
      [[nodiscard]] MaterialGraph* GetMaterialGraph() const { return m_MaterialGraph; }

			virtual void CreateNode(MATD::JSON JSONObj) = 0;
      virtual void RemoveNode(MATD::JSON JSONObj);
      virtual void AddConnection(MATD::JSON JSONObj);
      virtual void RemoveConnection(MATD::JSON JSONObj);
			virtual void Update(MATD::JSON JSONObj) = 0;
      virtual void Init(const MATD::JSON& JSONObj) = 0;

			std::map<int, Ref<MATD::GRAPH::Node>>* GetNodes() { return &m_Nodes; }
			Ref<MATD::GRAPH::Node> GetNode(const int& id) { return m_Nodes[id]; }
      void SetNode(const int& id, const Ref<Node>& node) { m_Nodes[id] = node; }
			
      std::map<std::string, Ref<MATD::GRAPH::Connection>>* GetConnections() { return &m_Connections; }
      Ref<MATD::GRAPH::Connection> GetConnection(const std::string& id) { return m_Connections[id]; }
			void AddToConnectionPool(const std::string& id, const Ref<Connection>& connection) { m_Connections[id] = connection; }
			void RemoveFromConnectionPool(const std::string& id) { m_Connections.erase(id); }
      void SetID(const std::string& id) { m_ID = id; }

			
      std::vector<Ref<MATD::GRAPH::Node>> GetOutputNodes();
      //Change connection statuses to IN_PROGRESS for the whole path
      void StartUpdate(Node* node, uint64_t time);
    private:
      std::string m_ID;
      MaterialGraph* m_MaterialGraph;
			std::map<int, Ref<MATD::GRAPH::Node>> m_Nodes;
      std::map<std::string, Ref<MATD::GRAPH::Connection>> m_Connections;
    };
  };
};
