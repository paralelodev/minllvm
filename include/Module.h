#include "Function.h"

namespace minllvm {
class Module : public Container<Function> {
public:
  void Remove(const std::string &functionName) {
    std::optional<Function *> function = Find(functionName);
    if (!function) {
      std::cerr << "Error: The function to be removed does not exist\n";
      exit(0);
    }

    for (auto &blockPair : (*function)->Elements) {
      const std::string &blockName = blockPair.first;
      (*function)->Remove(blockName);
      break;
    }

    Container::Remove(functionName);
  }

  void Dump(bool dumpElements) const {
    if (Elements.empty()) {
      std::cout << "--- empty ---\n";
      return;
    }

    for (auto &[functionName, function] : Elements) {
      std::cout << "Function: " << functionName << '\n';
      if (dumpElements) {
        function.Dump(dumpElements);
      }
    }

    std::cout << '\n';
  }
};
} // namespace minllvm
