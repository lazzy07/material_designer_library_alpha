#pragma once
#include "Argument.hpp"

namespace MATD{
  class Float : public Argument {
    Float(float val);

    float GetVal();
    void SetVal(float val);

    void Bind(const ENGINE::WorkItem* workItem, size_t index);
    void Delete();
  };
}