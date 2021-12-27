#pragma once
#include <string>
#include <map>
#include <json.hpp>

namespace MATD{
  using JSON = nlohmann::json;
  
  namespace CORE{

    class JSONParser {
    public:
      JSONParser();
      ~JSONParser();
      JSON ParseJSON(const std::string& JSONString);
    };
  }
}