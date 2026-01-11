#include "../include/problemsgen/problemsgen.h"
#include "../include/solutions/DP.h"
#include "../include/solutions/Knapsack.h"
#include <chrono>
#include <fstream>
#include <iostream>
#include <utility>
#include <vector>
void DisplayResult(const vector<int> &profit, const vector<int> &weight,
                   const Result &solution, long long timetaken) {
  cout << "------------------------------\n";
  cout << "Problem vectors:\n";
  cout << "Weights: ";
  for (int w : weight)
    cout << w << " ";
  cout << "\nValues:  ";
  for (int p : profit)
    cout << p << " ";
  cout << "\n\n";

  cout << "Chosen items (index | weight | value):\n";
  int totalW = 0, totalV = 0;
  for (int idx : solution.chosenItems) {
    cout << "  " << idx << " | " << weight[idx] << " | " << profit[idx] << "\n";
    totalW += weight[idx];
    totalV += profit[idx];
  }

  cout << "Total weight: " << totalW << "\n";
  cout << "Total value:  " << totalV << "\n";
  cout << "Max value returned: " << solution.maxValue << "\n";
  cout << "Time taken: " << timetaken << " ns\n";
  cout << "------------------------------\n";
}
void CompareKnapSackANDDP() {
  vector<pair<int, int>> problmscapandsize = {
      {16, 9},   {78, 100}, {50, 60},  {20, 10},  {30, 15},
      {40, 20},  {25, 12},  {35, 18},  {45, 22},  {55, 30},
      {60, 32},  {65, 35},  {70, 40},  {80, 45},  {90, 50},
      {100, 55}, {110, 60}, {120, 65}, {130, 70}, {140, 75},
      {150, 80}, {160, 85}, {170, 90}, {180, 95}, {190, 100}};

  ofstream csv("timecompariasion.csv");
  csv << "method,problem_size,time_ns,max_value\n";

  for (auto &problemcapandsize : problmscapandsize) {
    int capacity = problemcapandsize.first;
    int size = problemcapandsize.second;

    MARKETPROBLEM data = Gen_MarkteProblem(capacity, size);

    auto start = chrono::high_resolution_clock::now();
    Result solution = DP(capacity, data.EXPRETURN, data.MARKETPRICE);
    auto end = chrono::high_resolution_clock::now();
    long long timetaken =
        chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    DisplayResult(data.EXPRETURN, data.MARKETPRICE, solution, timetaken);

    csv << "DP," << size << "," << timetaken << "," << solution.maxValue
        << "\n";

    start = chrono::high_resolution_clock::now();
    Result solnknap = knapsack(capacity, data.EXPRETURN, data.MARKETPRICE);
    end = chrono::high_resolution_clock::now();
    timetaken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    DisplayResult(data.EXPRETURN, data.MARKETPRICE, solnknap, timetaken);

    csv << "Knapsack," << size << "," << timetaken << "," << solnknap.maxValue
        << "\n";
  }

  csv.close();
}
int main() {
  CompareKnapSackANDDP();
  return 0;
}
