#include "Module.h"

using namespace minllvm;

int main() {
  Module M;
  Function &F = M.Insert("main", Function());
  F.Insert("b1", Block(), "entry", "false");
  F.Insert("b2", Block(), "entry", "true");
  F.Insert("b3", Block(), "b2", "some_tag");
  F.Insert("b4", Block(), "b2", "other");
  M.Dump(true);
  F.Validate();
}
