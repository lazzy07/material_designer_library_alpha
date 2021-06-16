#pragma once
#include "../engine/WorkItem.hpp"

namespace MATD {
  class Int : public Argument {
  public:
    Int(int val);

    inline int GetVal() const { return m_Value; };
    inline void SetVal(int val) { m_Value = val; };

    virtual void Bind(const WorkItem* workItem, size_t index) = 0;
    virtual void Delete() = 0;
  private:
    int m_Value = 0;
  };
}