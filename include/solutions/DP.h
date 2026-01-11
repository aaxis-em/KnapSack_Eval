#ifndef DYNAMICP_H
#define DYNAMICP_H

#include "../problemsgen/problemsgen.h"
#include <algorithm>
#include <vector>
using namespace std;

int DPHELPER(int W, const vector<int> &val, const vector<int> &wt, int n,
             vector<vector<int>> &dp, vector<vector<bool>> &take) {
  if (n == 0 || W == 0)
    return 0;

  if (dp[n][W] != -1)
    return dp[n][W];

  int notPick = DPHELPER(W, val, wt, n - 1, dp, take);
  int pick = 0;

  if (wt[n - 1] <= W) {
    pick = val[n - 1] + DPHELPER(W - wt[n - 1], val, wt, n - 1, dp, take);
  }

  if (pick > notPick) {
    take[n][W] = true;
    dp[n][W] = pick;
  } else {
    dp[n][W] = notPick;
  }

  return dp[n][W];
}

Result DP(int W, const vector<int> &val, const vector<int> &wt) {
  int n = val.size();

  vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
  vector<vector<bool>> take(n + 1, vector<bool>(W + 1, false));

  int maxValue = DPHELPER(W, val, wt, n, dp, take);

  // reconstruction
  vector<int> chosen;
  int w = W;
  for (int i = n; i > 0; i--) {
    if (take[i][w]) {
      chosen.push_back(i - 1);
      w -= wt[i - 1];
    }
  }

  return {maxValue, chosen};
}

#endif
