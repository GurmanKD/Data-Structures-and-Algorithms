// assign + or - to each element such that the sum is givin to the target

// then return the no of such subsets possible

// exact same as prev: no of subsets with given difference

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> t2;

int topDownCountSubsets(vector<int> arr, int sum, int n) {
  t2 = vector<vector<int>>(n + 1, vector<int>(sum + 1, 0));

  // Initialization
  for (int i = 0; i <= n; i++) {
    t2[i][0] = 1;
  }
  for (int j = 1; j <= sum; j++) {
    t2[0][j] = 0;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= sum; j++) {
      if (arr[i-1] <= j) {
        t2[i][j] = t2[i-1][j-arr[i-1]] + t2[i-1][j];
      } else {
        t2[i][j] = t2[i-1][j];
      }
    }
  }

  return t2[n][sum];
}

int main() {
  vector<int> arr = {1, 1, 2, 3};
  int diff = 1;
  int totalSum = 0;
  for (int i = 0; i < arr.size(); i++) {
    totalSum += arr[i];
  }

  if ((totalSum + diff) % 2 != 0) {
    cout << "No subset with given diff found." << endl;
    return 0;
  }

  int sumS1 = (totalSum + diff) / 2;
  int n = arr.size();

  int count = topDownCountSubsets(arr, sumS1, n);
  if (count > 0) {
    cout << count << " subsets with given diff found." << endl;
  } else {
    cout << "No subset with given diff found." << endl;
  }

  return 0;
}

