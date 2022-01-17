#include "UUIDGenerator.hpp"

UUIDv4::UUIDGenerator<std::mt19937_64> MATD::CORE::UUIDGenerator::m_UUIDGenerator;

MATD::UUID MATD::CORE::UUIDGenerator::GenerateUUID()
{
	return m_UUIDGenerator.getUUID(); 
}
