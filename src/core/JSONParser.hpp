/**
 * @file JSONParser.hpp
 * @author Lasantha M Senanayake (222lasantha@gmail.com)
 * @brief Used to parse JSON strings
 * @version 0.1
 * @date 2024-11-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once
#include <string>
#include <map>
#include <json.hpp>

namespace MATD{
  using JSON = nlohmann::json;
  
  namespace CORE{
    /**
     * @brief JSON Parser class
     * Material Designer Editor uses JSON for configuration and data storage, this class is used to parse JSON strings. 
     * Specifically node graphs created by Rete.JS. This class uses nlohmann's JSON library.
     */
    class JSONParser {
    public:
      JSONParser();
      ~JSONParser();

      /**
       * @brief Parse a JSON string
       * 
       * @param JSONString JSON string to parse
       * @return JSON Parsed JSON object
       */
      JSON ParseJSON(const std::string& JSONString);
    };
  }
}