#pragma once

namespace MATD{
  namespace FUNC{
    class Function{
    public:
      virtual void Init() = 0;
      virtual void Calculate() = 0;
      virtual void Update() = 0;
    };
  }
}