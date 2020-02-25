#pragma once

#include "FileParser/Value.hpp"
#include "FileParser/JsonObject.hpp"
#include <string>
#include <string_view>

namespace json {

  class JsonParser {
  private:
    std::string_view::iterator it;
    std::string_view::iterator end;
    JsonObject jsonObject;     // object being populated
    JsonObject *currentObject; // current object parsed values are added to
                               // to allow for nested jsonObjects
  public:
    JsonParser(std::string_view string);
    JsonParser(JsonParser &&other) = default;

    char nextChar();

    JsonObject &detectInitialType();
    JsonObject &detectValueType(const std::string &key);

    JsonObject &parseKey();

    JsonObject &parseStringValue(const std::string &key);
    JsonObject &parseTrueValue(const std::string &key);
    JsonObject &parseFalseValue(const std::string &key);
    JsonObject &parseNullValue(const std::string &key);
    JsonObject &parseMapValue(const std::string &key);
  };

}
