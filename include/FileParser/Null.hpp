#pragma once

#include "FileParser/Value.hpp"

namespace json {

  class Null : public Value {
  protected:
    virtual std::ostream &printTo(std::ostream &os) const override;
  public:
    Null() = default;
    Null(const Null &other) = default;
    Null(Null &&other) = default;

    virtual ~Null() override = default;
  };

}
