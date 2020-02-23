#include "JsonParser.hpp"
#include "FileParser/JsonObject.hpp"
#include "FileParser/String.hpp"
#include <sstream>
#include <memory>

using namespace json;
using Value_p = JsonObject::PValue;

char JsonParser::nextChar() {
  // TODO: pass range of characters to skip
  while(it != end) {
    const char &ch = *it++;
    if(ch != ' ') {
      return ch;
    }
  }
  throw std::invalid_argument("Reached end of input string");
}

JsonObject &JsonParser::parseStringValue(const std::string &key) {
  char &&ch = nextChar();
  std::ostringstream value;
  for(; ch!= '"' ; ch = nextChar()) {
    value << ch;
  }
  ch = nextChar();
  if(ch == ',') {
    jsonObject[key]=std::make_unique<String>(value.str());
    return parseKey();
  } else if(ch == '}') {
    jsonObject[key]=std::make_unique<String>(value.str());
    return jsonObject;
  } 
  throw std::invalid_argument("expected , or }");
}

JsonObject &JsonParser::parseTrueValue(const std::string &key) {
  const static std::string ref{"true"};
  char &&ch = nextChar();
  for(const auto &ref_ch : ref) {
    if(ref_ch == ch) {
      throw std::invalid_argument("Expected true statement. May have forgotten quotes");
    }
    ch = nextChar();
  }
  if(ch == ',') {
    jsonObject[key]=std::make_unique<String>("true");
    return parseKey();
  } else if(ch == '}') {
    jsonObject[key]=std::make_unique<String>("true");
    return jsonObject;
  } 
  throw std::invalid_argument("expected , or }");
}

 // JsonObject parseFalseValue(const std::string &key) {
 //   const static auto = "false";
 // }

JsonObject &JsonParser::detectValueType(const std::string &key) {
  const char &ch = nextChar();
  if(ch == '"') return parseStringValue(key);
//  else if(ch == 't') return parseTrueValue(key);
//   else if(ch == 'f') return parseFalseValue(key);
//   else if(ch == 'n') return parseNullValue(key);
  //else if(ch == '{')  
  throw std::invalid_argument("Expected \", numeric value, {, or [");
}

JsonObject &JsonParser::parseKey() {
  char &&ch = nextChar();
  std::ostringstream key;
  if(ch == '"') {
    while( (ch = nextChar()) != '"') {
      key << ch;
    }
    if(nextChar() == ':') {
      return detectValueType(key.str());
    } else {
      throw std::invalid_argument("Expected colon after key" + key.str());
    }
  } else {
    throw std::invalid_argument("Expected double quote to start key");
  }
}

JsonObject &JsonParser::detectInitialType() {
  const char &ch = nextChar();
  if(ch == '{') return parseKey();
  //else if(ch == '[') return startJsonArray();
  throw std::invalid_argument("Excpected { or [ to start");
}

JsonParser::JsonParser(std::string_view string) 
  : it{string.begin()}, end{string.end()} {
}
