#pragma once
#include <string>
#include <map>
#include <json.hpp>

namespace MATD{
  using JSON = nlohmann::json;
  
  namespace CORE{

    class JSONParser {
    public:
      JSONParser(const std::string& JSONString);
      ~JSONParser();

      inline const JSON GetMap() { return m_Map; };

    private:
       JSON m_Map;
    };
  }
}