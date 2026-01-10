#ifndef PROBLEMSGEN_H
#define PROBLEMSGEN_H

#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
unsigned bounded_rand(unsigned max) {
  for (unsigned x, r;;)
    if (x = rand(), r = x % max, x - r <= -max)
      return r;
}
struct MARKETPROBLEM {
  std::vector<unsigned> MARKETPRICE; // weight
  std::vector<unsigned> EXPRETURN;   // value
};
// Random number < totalcapacity for MARKETPRICE
// Random number < someconstant for Expreturn
MARKETPROBLEM Gen_MarkteProblem(int TOTAL_CAPACITY, int sizeofproblem) {
  MARKETPROBLEM problem;
  std::srand(std::time({}));
  for (int i = 0; i < sizeofproblem; ++i) {
    unsigned weight = bounded_rand(TOTAL_CAPACITY);
    unsigned value = bounded_rand(20);
    problem.MARKETPRICE.push_back(weight);
    problem.EXPRETURN.push_back(value);
  }

  return problem;
}
#endif
