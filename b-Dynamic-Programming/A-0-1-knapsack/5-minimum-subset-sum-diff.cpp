#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<vector<int>> t2;

bool isSumPresentTopDown(vector<int> arr, int sum, int n) {
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= sum; j++) {
      if (j == 0)
        t2[i][j] = 1;
      else if (i == 0)
        t2[i][j] = 0;
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= sum; j++) {
      if (arr[i-1] <= j) {
        t2[i][j] = t2[i-1][j-arr[i-1]] || t2[i-1][j];
      } else {
        t2[i][j] = t2[i-1][j];
      }
    }
  }
  return t2[n][sum];
}

int findMinSubsetSumDiff(vector<int> arr, int n) {
  int range = 0;
  for (int i = 0; i < arr.size(); i++) {
    range += arr[i];
  }

  t2 = vector<vector<int>>(n + 1, vector<int>(range + 1, 0));
  
  // finding candidates for 1st subset
  isSumPresentTopDown(arr, range, n);

  vector<int> firstSubsetElements;

  for (int i = 0; i <= range / 2; i++) {
    if (t2[n][i] == 1) {
      firstSubsetElements.push_back(i);
    }
  }

  int minDiff = INT_MAX;
  for (int i = 0; i < firstSubsetElements.size(); i++) {
    minDiff = min(minDiff, range - 2 * firstSubsetElements[i]);
  }
  return minDiff;
}

int main() {
  vector<int> arr = {1, 2, 7};
  cout << "The minimum difference between two subsets is: " << findMinSubsetSumDiff(arr, arr.size()) << endl;
  return 0;
}
