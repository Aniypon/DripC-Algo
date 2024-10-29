#include "range.h"

int main() {

  for (int i : Range(3)) {
    std::cout << i << " ";  // 0 1 2
  }
  std::cout << std::endl;

  for (int i : Range(3, 6)) {
    std::cout << i << " ";  // 3 4 5
  }
  std::cout << std::endl;

  for (int i : Range(3, 6, 2)) {
    std::cout << i << " ";  // 3 5
  }
  std::cout << std::endl;

  for (int i : Range(6, 1, -2)) {
    std::cout << i << " ";  // 6 4 2
  }
  std::cout << std::endl;

  return 0;
}