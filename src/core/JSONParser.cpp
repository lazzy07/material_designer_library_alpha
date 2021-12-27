#include "JSONParser.hpp"
#include "Core.hpp"

MATD::CORE::JSONParser::JSONParser()
{
	MATD_CORE_TRACE("JSON_PARSER:: JSON parser initialized");
}

MATD::CORE::JSONParser::~JSONParser()
{
	MATD_CORE_TRACE("JSON_PARSER:: Destroyed");
}

MATD::JSON MATD::CORE::JSONParser::ParseJSON(const std::string& JSONString)
{
	return JSON::parse(JSONString);
}

