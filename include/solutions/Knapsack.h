#ifndef KNAPSACK_H
#define KNAPSACK_H

#include "../problemsgen/problemsgen.h"
#include <algorithm>
#include <vector>
using namespace std;

Result knapsack(int W, const vector<int> &val, const vector<int> &wt) {
  int n = wt.size();

  vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
  vector<vector<bool>> take(n + 1, vector<bool>(W + 1, false));

  for (int i = 1; i <= n; i++) {
    for (int w = 0; w <= W; w++) {
      dp[i][w] = dp[i - 1][w];

      if (w >= wt[i - 1]) {
        int candidate = dp[i - 1][w - wt[i - 1]] + val[i - 1];
        if (candidate > dp[i][w]) {
          dp[i][w] = candidate;
          take[i][w] = true;
        }
      }
    }
  }

  // reconstruct chosen items
  vector<int> chosen;
  int w = W;
  for (int i = n; i > 0; i--) {
    if (take[i][w]) {
      chosen.push_back(i - 1);
      w -= wt[i - 1];
    }
  }

  return {dp[n][W], chosen};
}

#endif
