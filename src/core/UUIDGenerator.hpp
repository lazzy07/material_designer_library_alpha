#pragma once
#include "uuid/uuid.h"

namespace MATD{
  using UUID = UUIDv4::UUID;
  namespace CORE{
    /**
     * @brief UUID Generator class, which is used to generate UUIDs for material nodes, graphs, etc. so that they can be uniquely identified
     * 
     */
    class UUIDGenerator{
    public:
      /**
       * @brief Generate a UUID
       * 
       * @return MATD::UUID Generated UUID
       */
      static MATD::UUID GenerateUUID();
    private:
      static UUIDv4::UUIDGenerator<std::mt19937_64> m_UUIDGenerator;
    };
  }
}