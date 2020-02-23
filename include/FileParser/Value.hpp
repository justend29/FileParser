#pragma once

#include <iostream>

namespace json {

  class Value {
  public:
    virtual std::ostream &printTo(std::ostream &os) const = 0;
    friend std::ostream &operator<<(std::ostream &os, const Value &v);
    virtual ~Value() = default;
  };

}
