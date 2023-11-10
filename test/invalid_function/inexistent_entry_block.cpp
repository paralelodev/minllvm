#include "Module.h"

using namespace minllvm;

int main() {
  Module M;
  Function &F = M.Insert("main", Function());
  F.Insert("b1", Block(), "entry", "false");
  F.Remove("entry");
  M.Dump(true);
  F.Validate();
}
