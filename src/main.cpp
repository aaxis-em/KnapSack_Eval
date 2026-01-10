#include "../include/problemsgen/problemsgen.h"
#include <iostream>

int main() {

  MARKETPROBLEM data = Gen_MarkteProblem(16, 9);

  for (auto value : data.MARKETPRICE) {
    std::cout << value << ",";
  }
  std::cout << "\n";
  for (auto value : data.EXPRETURN) {
    std::cout << value << ",";
  }
  return 0;
}
