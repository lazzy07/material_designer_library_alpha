#pragma once
#include <stdint.h>

namespace MATD {
  namespace CORE {
    /**
     * @brief Time class, which is used to get the current time in milliseconds
     * 
     */
    class Time {
    public:
      static uint64_t GetTime();
    };
  }
}
