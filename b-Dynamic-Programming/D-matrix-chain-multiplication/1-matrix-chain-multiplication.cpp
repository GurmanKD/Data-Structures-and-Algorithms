#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int recMCM(vector<int>dim, int i, int j){
  if(i >= j) return 0;
  int minCost = INT_MAX;

  // make 2 groups i - k-1, k - j
  // for(int k = i+1; k <= j; k++){}

  //--------OR----------//

  // make 2 groups i - k, k+1 - j
  for(int k = i; k < j; k++){
    int tempCost = recMCM(dim, i, k) + recMCM(dim, k+1, j) + dim[i-1]*dim[k]*dim[j];
    minCost = min(minCost, tempCost);
  }

  return minCost;
}

int main() {
  vector<int>dim = {10, 30, 5, 60};
  cout<<recMCM(dim, 1, 3);
  return 0;
}
