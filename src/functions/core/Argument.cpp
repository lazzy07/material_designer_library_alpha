#include "Argument.hpp"
#include "../../types/matd/MatdDataTypes.hpp"
#include "../../core/Core.hpp"

MATD::Ref<MATD::FUNC::Argument> MATD::FUNC::Argument::ArgumentFactory(MATD::JSON JSONObj)
{
	std::string dataType = JSONObj["dataType"].get<std::string>();
	std::string id = JSONObj["id"].get<std::string>();
	JSON data = JSONObj["data"];
	if (dataType == "number") {
		Number1* mem = (Number1*)malloc(sizeof(Number1));
		*mem = data.get<float>();

		return std::make_shared<Argument>(id, DATA_TYPES::NUMBER1, mem);
	}
	else if (dataType == "number2") {
		Number2* mem = (Number2*)malloc(sizeof(Number2));
		
		float num1 = data.at(0).get<float>();
		float num2 = data.at(1).get<float>();

		mem->x = num1;
		mem->y = num2;

		return std::make_shared<Argument>(id, DATA_TYPES::NUMBER2, mem);
	}
	else if (dataType == "colorvec") {
		ColorVec1* mem = (ColorVec1*)malloc(sizeof(ColorVec1));
		*mem = data.get<float>();

		return std::make_shared<Argument>(id, DATA_TYPES::COLORVEC1, mem);
	}
	else if (dataType == "colorvec3") {
		ColorVec3* mem = (ColorVec3*)malloc(sizeof(ColorVec3));

		float num1 = data.at(0).get<float>();
		float num2 = data.at(1).get<float>();
		float num3 = data.at(2).get<float>();

		mem->r = num1;
		mem->g = num2;
		mem->b = num3;

		return std::make_shared<Argument>(id, DATA_TYPES::COLORVEC3, mem);
	}
	else if (dataType == "lut") {

	}
	else if (dataType == "lut3") {

	}
	else if (dataType == "boolean") {
		bool* mem = (bool*)malloc(sizeof(bool));

		if (mem) {
			*mem = data.get<bool>();
		}

		return std::make_shared<Argument>(id, DATA_TYPES::COLORVEC3, mem);
	}
	else if (dataType == "string") {

	}
	MATD_CORE_WARN("Unknown type of Argument Recieved");
	return nullptr;
}

MATD::FUNC::Argument::Argument(std::string id, MATD::DATA_TYPES dataType, void* data) : m_ID(id), m_DataType(dataType), m_Data(data)
{
	MATD_CORE_TRACE("Argument created ID:{}", this->m_ID);
}

MATD::FUNC::Argument::~Argument()
{
	delete this->m_Data;
}