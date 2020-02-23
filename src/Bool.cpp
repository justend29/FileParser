#include "FileParser/Bool.hpp"

using namespace json;

Bool::Bool(const bool &value) : value{value} {
}

std::ostream &Bool::printTo(std::ostream &os) const {
  os << (this->value ? "true" : "false");
  return os;
}
