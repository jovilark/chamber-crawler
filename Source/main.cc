#include "testingMake.h"

int main() {
  Vec v {1,2};
  v = v + v;
  std::cout << v.x << std::endl;
  return 0;
}