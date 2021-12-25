#include "JSONParser.hpp"
#include "Core.hpp"

MATD::CORE::JSONParser::JSONParser(const std::string& JSONString)
{
	this->m_Map = JSON::parse(JSONString);
	MATD_CORE_TRACE("JSON_PARSER:: JSON parsing complete");
}

MATD::CORE::JSONParser::~JSONParser()
{
	MATD_CORE_TRACE("JSON_PARSER:: Destroyed");
}

