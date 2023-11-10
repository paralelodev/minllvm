#include "Block.h"
#include <optional>
#include <set>

namespace minllvm {
class Module;

class Function : public Container<Block> {
  friend Module;

public:
  Function() { Container::Insert("entry", Block()); }

  Block &Insert(const std::string &newBlockName, const Block &newBlock,
                const std::string &predecessorBlockName,
                const std::string &tagForNewBlock) {
    std::optional<Block *> predecessorBlock = Find(predecessorBlockName);
    if (!predecessorBlock) {
      std::cerr << "Error: Cannot insert the new block because the predecessor "
                   "block does not exist\n";
      exit(0);
    }

    (*predecessorBlock)->Insert(tagForNewBlock, newBlockName);
    return Container::Insert(newBlockName, newBlock);
  }

  void RemoveTags(const std::string &removedBlockName) {
    for (auto &blockPair : Elements) {
      Block &block = blockPair.second;
      for (auto &[tag, pointedBlockName] : block.Elements) {
        if (removedBlockName == pointedBlockName) {
          block.Remove(tag);
          break;
        }
      }
    }
  }

  void Remove(const std::string &blockName) {
    Container::Remove(blockName);
    RemoveTags(blockName);
  }

  void TraverseBlocks(std::set<std::string> &traversedBlockList,
                      const std::string &startingBlockName) {
    std::optional<Block *> startingBlock = Find(startingBlockName);
    if (!startingBlock) {
      std::cerr << "Error: Block to traverse from does not exist\n";
      return;
    }

    traversedBlockList.insert(startingBlockName);

    for (auto &stringPair : (*startingBlock)->Elements) {
      TraverseBlocks(traversedBlockList, stringPair.second);
    }
  }

  void Validate() {
    bool isValid = true;

    if (GetNumberOfElements() < 1) {
      std::cout << "Invalid: Function must have at least one block\n";
      isValid = false;
    }

    std::optional<Block *> entryBlock = Find("entry");
    if (!entryBlock) {
      std::cout << "Invalid: Function must have an 'entry' block\n";
      isValid = false;
    }

    std::set<std::string> BlockList;
    for (auto &blockPair : Elements) {
      BlockList.insert(blockPair.first);
    }

    std::set<std::string> TraversedBlockList;
    TraverseBlocks(TraversedBlockList, "entry");

    if (BlockList != TraversedBlockList) {
      std::cout << "Invalid: Some blocks could not be reached when traversing "
                   "the function\n";
      isValid = false;
    }

    if (isValid) {
      std::cout << "Valid Function\n";
    }
  }

  void Dump(bool dumpElements) const {
    if (Elements.empty()) {
      std::cout << "  --- empty ---\n";
      return;
    }

    for (auto &[blockName, block] : Elements) {
      std::cout << "  Block: " << blockName << '\n';
      if (dumpElements) {
        block.Dump();
      }
    }
  }
};
} // namespace minllvm
