#include "FileParser/String.hpp"

using namespace json;

String::String(const std::string &value) : value{value} {
}
String::String(std::string &&value) : value{value} {
}

std::ostream &String::printTo(std::ostream &os) const {
  os << '\"' << this->value << '\"';
  return os;
}
