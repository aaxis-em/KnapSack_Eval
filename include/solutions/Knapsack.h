#ifndef KNAPSACK_H
#define KNAPSACK_H

#include <algorithm>
#include <vector>

using namespace std;

unsigned knapsack(unsigned W, const vector<unsigned> &val,
                  const vector<unsigned> &wt) {
  vector<unsigned> dp(W + 1, 0);

  for (size_t i = 0; i < wt.size(); ++i) {
    for (unsigned j = W; j >= wt[i]; --j) {
      dp[j] = max(dp[j], dp[j - wt[i]] + val[i]);
      if (j == wt[i])
        break; // prevent unsigned underflow
    }
  }

  return dp[W];
}

#endif
