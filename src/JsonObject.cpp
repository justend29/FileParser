#include "FileParser/JsonObject.hpp"
#include <iostream>

using namespace json;

JsonObject::JsonObject(JsonMap &&map) : map{std::move(map)} {
}

//these may not work
JsonObject::mapped_type &JsonObject::operator[](const JsonObject::key_type &key) {
  return map[key];
}
JsonObject::mapped_type &JsonObject::operator[](JsonObject::key_type &&key) {
  return map[key];
}

std::ostream &JsonObject::printTo(std::ostream &os) const {
  for(const auto &pair : this->map) {
    os << '\"' << pair.first << "\":";
    (pair.second)->printTo(os) << ',';
  }
  return os;
}
