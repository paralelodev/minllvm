#include <iostream>
#include <map>
#include <optional>
#include <string>

namespace minllvm {

template <typename T> class Container {
protected:
  std::map<std::string, T> Elements;

public:
  T &Insert(const std::string &name, const T &element) {
    if (Elements.find(name) != Elements.end()) {
      std::cout << "Error: The new element to be inserted already exists\n";
      exit(0);
    }

    Elements[name] = std::move(element);

    return Elements[name];
  }

  void Remove(const std::string &name) {
    if (Elements.find(name) == Elements.end()) {
      std::cout << "Error: The element to be removed does not exist\n";
      exit(0);
    }

    Elements.erase(name);
  }

  std::size_t GetNumberOfElements() const { return Elements.size(); }

  std::optional<T *> Find(const std::string &name) {
    typename std::map<std::string, T>::iterator Element = Elements.find(name);
    if (Element == Elements.end()) {
      return std::nullopt;
    }

    return &Element->second;
  }
};

} // namespace minllvm
