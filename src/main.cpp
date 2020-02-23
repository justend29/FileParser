#include "FileParserConfig.hpp"
#include <iostream>
#include <string_view>

#include "FileParser/Value.hpp"
#include "FileParser/JsonObject.hpp"
#include "JsonParser.hpp"

//TODO look into next char returning a const ref

using namespace std::literals;
std::string_view jString = "{"
                        "  \"key\":\"value\","
                        "  \"another key\":\"another value\","
                        "  \"yet another key\":\"yet another value\""
                        "}"sv;

int main() {
  using namespace json;
  JsonParser parser(jString);
  const JsonObject &o = parser.detectInitialType();
  std::cout << o << std::endl;
}
