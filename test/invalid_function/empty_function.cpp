#include "Module.h"

using namespace minllvm;

int main() {
  Module M;
  Function &F = M.Insert("main", Function());
  F.Remove("entry");
  M.Dump(true);
  F.Validate();
}
