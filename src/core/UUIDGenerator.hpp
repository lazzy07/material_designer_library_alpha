#pragma once
#include "uuid/uuid.h"

namespace MATD{
  using UUID = UUIDv4::UUID;
  namespace CORE{

    class UUIDGenerator{
    public:
      static MATD::UUID GenerateUUID();
    private:
      static UUIDv4::UUIDGenerator<std::mt19937_64> m_UUIDGenerator;
    };
  }
}