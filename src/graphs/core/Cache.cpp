#include "Cache.hpp"

void MATD::GRAPH::Cache::SetCache(std::string key, void* value)
{
	this->m_Map.insert(std::pair<std::string, void*>(key, value));
}

template<class T>
inline T* MATD::GRAPH::Cache::GetCache(std::string key)
{
	return (T)this->m_Map.find(key);
}