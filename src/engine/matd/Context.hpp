#pragma once
#include <vector>
#include "../../core/Core.hpp"
#include "Platform.hpp"

namespace MATD{
  namespace ENGINE{
    class Context{
      public:
        virtual ~Context() {};

        virtual std::vector<Ref<Platform>> GetSupportedPlatforms() = 0;

        static Ref<Context> CreateContext();

        inline void SetPlatforms(std::vector<Ref<Platform>> platforms) { m_Platforms = platforms; };

      private:
        std::vector<Ref<Platform>> m_Platforms;
    };
  };
}