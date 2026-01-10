#include "../include/problemsgen/problemsgen.h"
#include "../include/solutions/DP.h"
#include "../include/solutions/Knapsack.h"
#include <chrono>
#include <iostream>
#include <utility>
#include <vector>
int main() {
  std::vector<std::pair<unsigned, unsigned>> problmscapandsize = {
      std::make_pair(16, 9), std::make_pair(30, 10)};
  for (auto problemcapandsize : problmscapandsize) {
    MARKETPROBLEM data =
        Gen_MarkteProblem(problemcapandsize.first, problemcapandsize.second);
    auto start = std::chrono::high_resolution_clock::now();
    std::cout << "Weight="
              << DP(problemcapandsize.first, data.EXPRETURN, data.MARKETPRICE)
              << "\n";
    auto end = chrono::high_resolution_clock::now();
    cout << std::chrono::duration_cast<chrono::nanoseconds>(end - start).count()
         << "ns\n";
    start = std::chrono::high_resolution_clock::now();
    std::cout << "Weight="
              << knapsack(problemcapandsize.first, data.EXPRETURN,
                          data.MARKETPRICE)
              << "\n";
    end = chrono::high_resolution_clock::now();
    cout << std::chrono::duration_cast<chrono::nanoseconds>(end - start).count()
         << "ns\n";
  }

  return 0;
}
