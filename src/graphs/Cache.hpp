#pragma once
#include <map>
#include <string>

namespace MATD{
  namespace GRAPH{
    class Cache{
    public:
      void SetCache(std::string key, void* value);

      template<class T>
      T* GetCache(std::string key);
    private:
      std::map<std::string, void*> m_Map;
    };
  }
}