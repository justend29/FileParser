#pragma once

#include <unordered_map>
#include <string>
#include <memory>

#include "FileParser/Value.hpp"

namespace json {

  class JsonObject : public Value {
  private:
    using JsonMap = std::unordered_map<std::string, std::unique_ptr<Value>>;
    JsonMap map;
  protected:
    std::ostream &printTo(std::ostream &os) const override;
  public:  
    using value_type = typename JsonMap::value_type;
    using iterator = typename JsonMap::iterator;
    using const_iterator = typename JsonMap::const_iterator;
    using key_type = typename JsonMap::key_type;
    using mapped_type = typename JsonMap::mapped_type;
    using PValue = mapped_type;

    JsonObject() noexcept = default;
    JsonObject(const JsonObject &other) = delete;
    JsonObject(JsonObject &&other) = default;
    JsonObject(const JsonMap &map) = delete;
    JsonObject(JsonMap &&map);

    std::pair<iterator,bool> insert(const value_type &val) = delete;
    mapped_type &operator[](const key_type &key);
    mapped_type &operator[](key_type &&key);

    virtual ~JsonObject() override = default;
  };

}
