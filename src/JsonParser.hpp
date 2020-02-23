#pragma once

#include "FileParser/Value.hpp"
#include "FileParser/JsonObject.hpp"
#include <string>
#include <string_view>

namespace json {

  class JsonParser {
  public:
    char nextChar();

    JsonObject &parseStringValue(const std::string &key);

    JsonObject &parseTrueValue(const std::string &key);

   // JsonObject parseFalseValue(const std::string &key) {
   //   const static auto = "false";
   // }

    JsonObject &detectValueType(const std::string &key);

    JsonObject &parseKey();

    JsonObject &detectInitialType();

    JsonParser(std::string_view string);

  private:
    std::string_view::iterator it;
    std::string_view::iterator end;
    JsonObject jsonObject;
  };

}
