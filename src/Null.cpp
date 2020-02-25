#include "FileParser/Null.hpp"

using namespace json;

std::ostream &Null::printTo(std::ostream &os) const {
  os << "null";
  return os;
}
