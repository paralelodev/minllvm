#include "Module.h"

using namespace minllvm;

int main() {
  Module M;
  Function &F = M.Insert("main", Function());
  F.Insert("b1", Block(), "entry", "false");
  F.Insert("b2", Block(), "b1", "true");
  F.Insert("b3", Block(), "b2", "false");
  F.Remove("b2");
  M.Dump(true);
  F.Validate();
}
