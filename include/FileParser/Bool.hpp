#pragma once

#include "FileParser/Value.hpp"

namespace json {

  class Bool : public Value {
  private:
    bool value;
  protected:
    virtual std::ostream &printTo(std::ostream &os) const override;
  public:
    Bool() = default;
    Bool(const Bool &other) = default;
    Bool(Bool &&other) = default;
    Bool(const bool &value);
    // no need to move construct a boolean

    virtual ~Bool() override = default;
  };

}
