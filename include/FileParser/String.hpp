#pragma once

#include <string>
#include "FileParser/Value.hpp"

namespace json {

  class String : public Value {
  private:
    std::string value;
  protected:
    virtual std::ostream &printTo(std::ostream &os) const override;
  public:
    String() = default;
    String(const String &other) = default;
    String(String &&other) = default;
    String(const std::string &value);
    String(std::string &&value);

    virtual ~String() override = default;
  };

}
