#ifndef DYNAMICP_H
#define DYNAMICP_H
#include <vector>
using namespace std;
int DPHELPER(int W, vector<unsigned> &val, vector<unsigned> &wt, int n) {

  // Base Case
  if (n == 0 || W == 0)
    return 0;

  int pick = 0;

  // Pick nth item if it does not exceed the capacity of knapsack
  if (wt[n - 1] <= W)
    pick = val[n - 1] + DPHELPER(W - wt[n - 1], val, wt, n - 1);

  // Don't pick the nth item
  int notPick = DPHELPER(W, val, wt, n - 1);

  return max(pick, notPick);
}

int DP(int W, vector<unsigned> &val, vector<unsigned> &wt) {
  int n = val.size();
  return DPHELPER(W, val, wt, n);
}
#endif
