#ifndef PROBLEMSGEN_H
#define PROBLEMSGEN_H

#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
int bounded_rand(int max) {
  int x, r;
  do {
    x = rand();
    r = x % max;
  } while (x - r > RAND_MAX - max + 1);
  return r;
}
struct MARKETPROBLEM {
  std::vector<int> MARKETPRICE; // weight
  std::vector<int> EXPRETURN;   // value
};

struct Result {
  int maxValue;
  std::vector<int> chosenItems;
};
// Random number < totalcapacity for MARKETPRICE
// Random number < someconstant for Expreturn
MARKETPROBLEM Gen_MarkteProblem(int TOTAL_CAPACITY, int sizeofproblem) {
  MARKETPROBLEM problem;
  std::srand(std::time({}));
  for (int i = 0; i < sizeofproblem; ++i) {
    int weight = bounded_rand(TOTAL_CAPACITY);
    int value = bounded_rand(20);
    problem.MARKETPRICE.push_back(weight);
    problem.EXPRETURN.push_back(value);
  }

  return problem;
}
#endif
