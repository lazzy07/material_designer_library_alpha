#include "Argument.hpp"
#include "../../types/matd/MatdDataTypes.hpp"
#include "../../core/Core.hpp"
#include <string.h>

MATD::DATA_TYPES MATD::FUNC::Argument::StringToArgumentType(std::string str)
{
	if (str == "number") {
		return DATA_TYPES::NUMBER1;
	}
	else if (str == "number2") {
		return DATA_TYPES::NUMBER2;
	}
	else if (str == "colorvec") {
		return DATA_TYPES::COLORVEC1;
	}
	else if (str == "colorvec3") {
		return DATA_TYPES::COLORVEC3;
	}
	else if (str == "lut") {
		return DATA_TYPES::LUT1;
	}
	else if (str == "lut3") {
		return DATA_TYPES::LUT3;
	}
	else if (str == "boolean") {
		return DATA_TYPES::BOOLEAN;
	}
	else if (str == "string") {
		return DATA_TYPES::STRING;
	}
	else {
		MATD_CORE_ASSERT(false, "Data type not found!");
		return DATA_TYPES::BOOLEAN;
	}
}

MATD::Ref<MATD::FUNC::Argument> MATD::FUNC::Argument::ArgumentFactory(MATD::JSON JSONObj)
{
	std::string dataTypeStr = JSONObj["dataType"].get<std::string>();
	DATA_TYPES dataType = Argument::StringToArgumentType(dataTypeStr);
	std::string id = JSONObj["id"].get<std::string>();
	JSON data = JSONObj["data"];


	switch (dataType)
	{
	case MATD::DATA_TYPES::NUMBER1:
	{
		Number1* mem = (Number1*)malloc(sizeof(Number1));

		if (mem) {
			float val = data.get<float>();
			memcpy(mem, &val, sizeof(Number1));
		}
		return std::make_shared<Argument>(id, DATA_TYPES::NUMBER1, mem);
	}
		
		break;
	case MATD::DATA_TYPES::NUMBER2:
	{
		Number2* mem2 = (Number2*)malloc(sizeof(Number2));

		float num1 = data.at(0).get<float>();
		float num2 = data.at(1).get<float>();

		mem2->x = num1;
		mem2->y = num2;

		return std::make_shared<Argument>(id, DATA_TYPES::NUMBER2, mem2);
	}
		break;
	case MATD::DATA_TYPES::STRING:
	{
		StringElem* mem = (StringElem*)malloc(sizeof(StringElem));
		std::string str = data.get<std::string>();

		size_t size = sizeof(char) * (str.length() + 1);
		char* strMem = (char*)malloc(size);

		if (mem && strMem) {
			strcpy(strMem, str.c_str());
			mem->size = size;
			mem->str = strMem;
		}

		return std::make_shared<Argument>(id, DATA_TYPES::STRING, mem);
	}
		break;
	case MATD::DATA_TYPES::BOOLEAN:
	{
		bool* bl = (bool*)malloc(sizeof(bool));

		if (bl) {
			*bl = data.get<bool>();
		}

		return std::make_shared<Argument>(id, DATA_TYPES::BOOLEAN, bl);
	}
		break;
	case MATD::DATA_TYPES::COLORVEC1:
	{
		ColorVec1* col1 = (ColorVec1*)malloc(sizeof(ColorVec1));
		if (col1) {
			*col1 = data.get<float>();
		}
		return std::make_shared<Argument>(id, DATA_TYPES::COLORVEC1, col1);
	}
		break;
	case MATD::DATA_TYPES::COLORVEC3:
	{
		ColorVec3* col3 = (ColorVec3*)malloc(sizeof(ColorVec3));

		if (col3) {
			col3->b = data.at(0).get<float>();
			col3->g = data.at(1).get<float>();
			col3->r = data.at(2).get<float>();
		}
		return std::make_shared<Argument>(id, DATA_TYPES::COLORVEC3, col3);
	}
		break;
	case MATD::DATA_TYPES::LUT1:
		break;
	case MATD::DATA_TYPES::LUT3:
		break;
	default:
		break;
	}

	
	MATD_CORE_WARN("Unknown type of Argument Recieved");
	return nullptr;
}


MATD::FUNC::Argument::Argument(std::string id, MATD::DATA_TYPES dataType, void* data) : m_ID(id), m_DataType(dataType), m_Data(data)
{
	MATD_CORE_TRACE("MATD::FUNC Argument created ID:{}", this->m_ID);
}

MATD::FUNC::Argument::~Argument()
{
	delete this->m_Data;
}

void MATD::FUNC::Argument::SetData(MATD::JSON JSONObj)
{
	std::string dataTypeStr = JSONObj["dataType"].get<std::string>();
	DATA_TYPES dataType = Argument::StringToArgumentType(dataTypeStr);
	MATD::JSON data = JSONObj["data"];

	if (this->GetDataType() != dataType) {
		MATD_CORE_ERROR("Data type mismatch in the argument!");
		return;
	}

	switch (dataType) {
	case DATA_TYPES::NUMBER1:
	{
		float num = data.get<float>();
		this->SetData<Number1>(num);
	}
		break;

	case DATA_TYPES::NUMBER2:
	{
		Number2 mem;

		float num1 = data.at(0).get<float>();
		float num2 = data.at(1).get<float>();
		mem.x = num1;
		mem.y = num2;

		this->SetData<Number2>(mem);
	}
		break;
	case DATA_TYPES::COLORVEC1:
	{
		ColorVec1 vec;

		float num1 = data.get<float>();
		vec = num1;
		this->SetData<ColorVec1>(vec);
	}
		break;
	case DATA_TYPES::COLORVEC3:
	{
		ColorVec3 vec3;

		vec3.b = data.at(0).get<float>();
		vec3.g = data.at(1).get<float>();
		vec3.r = data.at(2).get<float>();
		this->SetData<ColorVec3>(vec3);
	}
		break;
	case DATA_TYPES::BOOLEAN:
	{
		bool val = data.get<bool>();
		this->SetData<bool>(val);
	}
		break;
	case DATA_TYPES::LUT1:
	{
		auto d = this->GetData<std::vector<Ref<Lut1Elem>>>();
		d->clear();

		for (auto i = data.begin(); i < data.end(); i++) {
			Ref<Lut1Elem> ele = std::make_shared<Lut1Elem>();

			float col = i.value()["col"].get<float>();
			int pos = i.value()["pos"].get<int>();

			ele->color = col;
			ele->pos = pos;

			d->push_back(ele);
		}
	}
		break;
	case DATA_TYPES::LUT3:
	{
		auto d = this->GetData<std::vector<Ref<Lut3Elem>>>();
		d->clear();

		for (auto i = data.begin(); i < data.end(); i++) {
			Ref<Lut3Elem> ele = std::make_shared<Lut3Elem>();

			std::string col = i.value()["col"].get<std::string>();
			int pos = i.value()["pos"].get<int>();
			float r, g, b;
			sscanf(col.c_str(), "#%02x%02x%02x", &r, &g, &b);

			ele->color.r = r;
			ele->color.g = g;
			ele->color.b = b;

			ele->pos = pos;

			d->push_back(ele);
		}
	}
		break;
	case DATA_TYPES::STRING:
	{
		std::string str = data.get<std::string>();
		StringElem* mem = this->GetData<StringElem>();
		
		size_t size = sizeof(char) * (str.length() + 1);
		char* strMem = (char*)malloc(size);
		strcpy(strMem, str.c_str());
		delete mem->str;

		mem->size = size;
		mem->str = strMem;
	}
		break;
	}
}