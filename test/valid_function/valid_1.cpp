#include "Module.h"

using namespace minllvm;

int main() {
  Module M;
  Function &F1 = M.Insert("main", Function());
  F1.Insert("b1", Block(), "entry", "false");
  F1.Insert("b2", Block(), "entry", "true");
  F1.Insert("b3", Block(), "b2", "some_tag");
  F1.Insert("b4", Block(), "b2", "other");

  F1.Validate();

  Function &F2 = M.Insert("foo", Function());
  F2.Insert("c1", Block(), "entry", "1");
  F2.Insert("c2", Block(), "c1", "2");
  F2.Insert("c3", Block(), "c1", "some_tag");
  F2.Insert("c4", Block(), "c1", "other");
  F2.Insert("c5", Block(), "c2", "other");

  F2.Validate();
}
