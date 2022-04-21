#include "Argument.hpp"
#include "../../types/matd/MatdDataTypes.hpp"
#include "../../core/Core.hpp"
#include <string.h>
#include "../../types/matd/Argument.hpp"

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
	else if (str == "color") {
		return DATA_TYPES::TEXCOLOR;
	}
	else if (str == "grayscale") {
		return DATA_TYPES::TEXGRAYSCALE;
	}
	else {
		MATD_CORE_ASSERT(false, "Data type not found!");
		return DATA_TYPES::BOOLEAN;
	}
}

MATD::Ref<MATD::FUNC::Argument> MATD::FUNC::Argument::ArgumentFactory(const std::string& id, DATA_TYPES dataType)
{
	void* mem = nullptr;
	switch (dataType)
	{
	case MATD::DATA_TYPES::NUMBER1:
	{
		mem = malloc(sizeof(Number1));
	}
		break;
	case MATD::DATA_TYPES::NUMBER2:
	{
		mem = malloc(sizeof(Number2));
	}
		break;
	case MATD::DATA_TYPES::STRING:
	{
		mem = new std::string("");
	}
		break;
	case MATD::DATA_TYPES::BOOLEAN:
	{
		mem = malloc(sizeof(bool));
	}
		break;
	case MATD::DATA_TYPES::COLORVEC1:
	{
		mem = malloc(sizeof(ColorVec1));
	}
		break;
	case MATD::DATA_TYPES::COLORVEC3:
	{
		mem = malloc(sizeof(ColorVec3));
	}
		break;
	case MATD::DATA_TYPES::LUT1:
	{
		mem = malloc(sizeof(Lut1));
	}
		break;
	case MATD::DATA_TYPES::LUT3: 
	{
		mem = malloc(sizeof(Lut3));
	}
		break;
	}

	if (mem) {
		return std::make_shared<FUNC::Argument>(id, dataType, mem);
	}

	MATD_CORE_WARN("Unknown type of Argument Recieved");
	return nullptr;
}

MATD::Ref<MATD::DTYPES::Argument> MATD::FUNC::Argument::Serialize(MATD::FUNC::Argument* argument)
{
	MATD::Ref<MATD::DTYPES::Argument> ref;
	switch (argument->GetDataType())
	{
	case MATD::DATA_TYPES::NUMBER1:
	{
		float data = *(argument->GetData<Number1>());
		auto arg = MATD::Argument::Float(data);
		ref.reset((DTYPES::Argument*)arg);
	}
		break;
	case MATD::DATA_TYPES::NUMBER2:
	{
		Number2 data = *(argument->GetData<Number2>());
		auto arg = MATD::Argument::Number2(data);
		ref.reset((DTYPES::Argument*)arg);
	}
		break;
	case MATD::DATA_TYPES::STRING:
		break;
	case MATD::DATA_TYPES::BOOLEAN:
	{
		bool data = *(argument->GetData<bool>());
		auto arg = MATD::Argument::Int((int)data);
		ref.reset((DTYPES::Argument*)arg);
	}
		break;
	case MATD::DATA_TYPES::COLORVEC1:
	{
		float data = *(argument->GetData<ColorVec1>());
		auto arg = MATD::Argument::Float(data);
		ref.reset((DTYPES::Argument*)arg);
	}
		break;
	case MATD::DATA_TYPES::COLORVEC3:
	{
		ColorVec3 data = *(argument->GetData<ColorVec3>());
		auto arg = MATD::Argument::ColorVec3(data);
		ref.reset((DTYPES::Argument*)arg);
	}
		break;
	case MATD::DATA_TYPES::LUT1:
	{
		Lut1 data = *(argument->GetData<Lut1>());
		auto arg = MATD::Argument::Buffer(data.stops, data.length, sizeof(Lut1Elem), MATD::ARG_TYPE::DEVICE_READ);
		ref.reset((DTYPES::Argument*)arg);
	}
		break;
	case MATD::DATA_TYPES::LUT3:
	{
		Lut3 data = *(argument->GetData<Lut3>());
		auto arg = MATD::Argument::Buffer(data.stops, data.length, sizeof(Lut3Elem), MATD::ARG_TYPE::DEVICE_READ);
		ref.reset((DTYPES::Argument*)arg);
	}
		break;
	default:
		MATD_CORE_ERROR("MATD::FUNC Unknown argument datatype found");
		{
			return nullptr;
		}
		break;
	}

	return ref;
}

MATD::Ref<MATD::FUNC::Argument> MATD::FUNC::Argument::ArgumentFactory(MATD::JSON JSONObj)
{
	std::string dataTypeStr = JSONObj["dataType"].get<std::string>();
	std::string inputTypeStr = JSONObj["inputType"].get<std::string>();
	DATA_TYPES dataType = Argument::StringToArgumentType(dataTypeStr);
	std::string id = JSONObj["id"].get<std::string>();
	JSON data = JSONObj["data"];


	switch (dataType)
	{
	case MATD::DATA_TYPES::NUMBER1:
	{
		Number1* mem = (Number1*)malloc(sizeof(Number1));

		if (mem) {
			if(inputTypeStr == "dropdown"){
				std::string val = data["value"].get<std::string>();
				float data = std::stof(val);
				memcpy(mem, &data, sizeof(Number1));
			}
			else {
				float val = data.get<float>();
				memcpy(mem, &val, sizeof(Number1));
			}
		}
		return std::make_shared<Argument>(id, DATA_TYPES::NUMBER1, mem);
	}
		
		break;
	case MATD::DATA_TYPES::NUMBER2:
	{
		Number2* mem2 = (Number2*)malloc(sizeof(Number2));

		float num1 = data.at(0).get<float>();
		float num2 = data.at(1).get<float>();

		if (mem2) {
			mem2->x = num1;
			mem2->y = num2;
		}

		return std::make_shared<Argument>(id, DATA_TYPES::NUMBER2, mem2);
	}
		break;
	case MATD::DATA_TYPES::STRING:
	{
		std::string str = data.get<std::string>();
		auto mem = new std::string(str);

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
			std::string col = data.get<std::string>();
			unsigned int r, g, b;
			int val = sscanf(col.c_str(), "#%02x%02x%02x", &r, &g, &b);

			col3->b = (float)b;
			col3->g = (float)g;
			col3->r = (float)r;
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
		std::string col = data.get<std::string>();
		unsigned int r, g, b;
		int val = sscanf(col.c_str(), "#%02x%02x%02x", &r, &g, &b);

		vec3.b = (float)b;
		vec3.g = (float)g;
		vec3.r = (float)r;
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
		auto d = this->GetData<Lut1>();
		delete d->stops;

		size_t length = data.size();
		Lut1Elem* stops = (Lut1Elem*)malloc(sizeof(Lut1Elem) * length);
		
		d->stops = stops;
		d->length = length;

		int j = 0;
		for (auto i = data.begin(); i < data.end(); i++) {
			float col = i.value()["col"].get<float>();
			int pos = i.value()["pos"].get<int>();

			if (stops) {
				stops[j].color = col;
				stops[j].pos = pos;
			}

			j++;
		}
	}
		break;
	case DATA_TYPES::LUT3:
	{
		auto d = this->GetData<Lut3>();
		delete d->stops;

		size_t length = data.size();
		Lut3Elem* stops = (Lut3Elem*)malloc(sizeof(Lut3Elem) * length);
		
		d->length = length;
		d->stops = stops;
		
		int j = 0;
		for (auto i = data.begin(); i < data.end(); i++) {
			std::string col = i.value()["col"].get<std::string>();
			int pos = i.value()["pos"].get<int>();
			unsigned int r, g, b;
			int val = sscanf(col.c_str(), "#%02x%02x%02x", &r, &g, &b);

			if (stops) {
				stops[j].color.r = (float)r;
				stops[j].color.g = (float)g;
				stops[j].color.b = (float)b;
				stops[j].pos = pos;
			}

			j++;
		}
	}
		break;
	case DATA_TYPES::STRING:
	{
		std::string str = data.get<std::string>();
		std::string* mem = this->GetData<std::string>();
		
		delete mem;

		m_Data = new std::string(str);
	}
		break;
	}
}