#include "FileParser/Value.hpp"

namespace json {

std::ostream &operator<<(std::ostream &os, const Value &v) {
  return v.printTo(os);
}

}
