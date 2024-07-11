#include<iostream>
#include<vector>
using namespace std;

int recCountSubsets(vector<int> arr, int sum, int n){
  if(sum != 0 && n == 0){
    return 0;
  }
  if(sum == 0){
    return 1;
  }
  if(arr[n-1] <= sum){
    return recCountSubsets(arr, sum-arr[n-1], n-1) + recCountSubsets(arr, sum, n-1);
  }else{
    return recCountSubsets(arr, sum, n-1);
  }
}

int static t1[7][11];

int memoCountSubsets(vector<int> arr, int sum, int n){
  if(sum != 0 && n == 0){
    return 0;
  }
  if(sum == 0){
    return 1;
  }
  
  if(t1[n][sum] != -1){
    return t1[n][sum];
  }

  if(arr[n-1] <= sum){
    return t1[n][sum] = memoCountSubsets(arr, sum-arr[n-1], n-1) + memoCountSubsets(arr, sum, n-1);
  }else{
    return t1[n][sum] = memoCountSubsets(arr, sum, n-1);
  }
}

int static t2[7][11];

int topDownCountSubsets(vector<int> arr, int sum, int n){

  // Initialization
  for(int i = 0; i < n; i++){
    for(int j = 0; j < sum; j++){
      if(j == 0) 
        t2[i][j] = 1;
      else if(i == 0) 
        t2[i][j] = 0;
    }
  }

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= sum; j++){
      if(arr[i-1] <= j){
        t2[i][j] = t2[i-1][j-arr[i-1]] + t2[i-1][j];
      }else{
        t2[i][j] = t2[i-1][j];
      }
    }
  }

  return t2[n][sum];
}

int main(){
  vector<int> arr = {2, 3, 5, 6, 8, 10};
  int sum = 10;
  int n = arr.size();

  // if (recCountSubsets(arr, sum, n)) {
  //       cout << recCountSubsets(arr, sum, n)<<" subsets with given sum found." << endl;
  // }else{
  //       cout << "No subset with given sum found." << endl;
  // }

  // memset(t1, -1, sizeof(t1));

  // if (memoCountSubsets(arr, sum, n)){
  //       cout << memoCountSubsets(arr, sum, n)<<" subsets with given sum found." << endl;
  // }else{
  //       cout << "No subset with given sum found." << endl;
  // }

  if (topDownCountSubsets(arr, sum, n)){
        cout << topDownCountSubsets(arr, sum, n)<<" subsets with given sum found." << endl;
  }else{
        cout << "No subset with given sum found." << endl;
  }

  return 0;
}
