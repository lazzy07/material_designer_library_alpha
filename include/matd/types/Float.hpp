#pragma once
#include "Argument.hpp"

namespace MATD {
  class Float : public DTYPES::Argument {
  public:
    Float(size_t id, float val);

    inline float GetVal() const { return m_Value; };
    inline void SetVal(float val) { m_Value = val; };

    virtual void Bind(const WorkItem* workItem, size_t index) = 0;
    virtual void Delete() = 0;
  private:
    float m_Value  = 0.0f;
  };
}