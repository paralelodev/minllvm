#include "Module.h"

using namespace minllvm;

int main() {
  Module M;
  M.Insert("main", Function());
  M.Insert("main", Function());
}
