#pragma once 

#include <vector>

#include "FileParser/Value.hpp"

namespace json {

  template<typename Arr=std::vector<Value>>
  class Array : public Value {
  private:
    Arr array;
  protected:
    std::ostream &printTo(std::ostream &os) const override {
      os << '[';
      auto it = this->array.begin();
      auto end = this->array.end()-1;
      for(;it<end; ++it) {
        os << *it << ", ";
      }
      os << *it << ']';
      return os;
    }
  public:
    using value_type = typename Arr::value_type;
    using container_type = Arr;

    Array() = default;
    Array(const Array &other) = default;
    Array(Array &&other) = default;
    Array(const Arr &array) : array{array} {
    }
    Array(Arr &&array) : array{array} {
    }
    //template<typename...Args>
    //Array(Args&&...args) {
    //    array(std::forward<Args>(args)...);
    //}

    virtual ~Array() override = default;
  };

}
