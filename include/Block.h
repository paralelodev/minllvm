#include "Container.h"

namespace minllvm {
class Function;

class Block : public Container<std::string> {
  friend Function;

public:
  void Dump() const {
    if (Elements.empty()) {
      std::cout << "    --- empty ---\n";
      return;
    }

    for (auto &[tagName, blockName] : Elements) {
      std::cout << "    Tag: " << tagName << " -> " << blockName << '\n';
    }
  }
};
} // namespace minllvm
