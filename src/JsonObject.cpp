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
  os << "{ ";
  const_iterator it=this->map.cbegin();
  const_iterator stored_it = it;
  const_iterator end = this->map.cend();
  // print all elements but first w/ comma
  while(++it!=end) {
    os << '\"' << (*it).first << "\":";
    ((*it).second)->printTo(os) << ',';
  }
  // print last element w/o comma
  os << '\"' << (*stored_it).first << "\":";
  ((*stored_it).second)->printTo(os) << " }";
  return os;
}
