/*
Check whether a subset with the given sum is present in the array or not.
*/

#include<iostream>
#include<vector>
#include<stdbool.h>

using namespace std;

bool isSumPresentRecursive(vector<int> arr, int sum, int n){
  if(n == 0 && sum != 0){
    return false;
  }
  if(sum == 0){
    return true;
  }
  if(arr[n-1] <= sum){
    return isSumPresentRecursive(arr, sum-arr[n-1], n-1) || isSumPresentRecursive(arr, sum, n-1);
  }else{
    return isSumPresentRecursive(arr, sum, n-1);
  }
}

int static t1[6][12];

bool isSumPresentMemo(vector<int> arr, int sum, int n){
  if(n == 0 && sum != 0){
    return false;
  }
  if(sum == 0){
    return true;
  }
  if(t1[n][sum] != -1){
    return t1[n][sum];
  }
  if(arr[n-1] <= sum){
    return t1[n][sum] = isSumPresentMemo(arr, sum-arr[n-1], n-1) || isSumPresentMemo(arr, sum, n-1);
  }else{
    return t1[n][sum] = isSumPresentMemo(arr, sum, n-1);
  }
}

static int t2[6][12];

bool isSumPresentTopDown(vector<int> arr, int sum, int n){

  // Initialisation
  for(int i = 0; i < n+1; i++){
    for(int j =0; j < sum+1; j++){
      if(j == 0)
        t2[i][j] = 1;
      if(i == 0)
        t2[i][j] = 0;
    }
  }

  for(int i = 1; i < n+1; i++){
    for(int j =1; j < sum+1; j++){
      if(arr[i-1] <= sum){
        t2[i][j] = t2[i-1][j-arr[i-1]] || t2[i-1][ j];
      }
      else{
        t2[i][j] = t2[i-1][j];
      }
    }
  }
  return t2[n][sum];
  
}

int main(){
  vector<int> arr = {2, 3, 7, 8, 10};
  int sum = 11;
  int n = arr.size();

  // if (isSumPresentRecursive(arr, sum, n)) {
  //       cout << "Subset with given sum found." << endl;
  // }else{
  //       cout << "No subset with given sum found." << endl;
  // }

  // memset(t1, -1, sizeof(t1));

  // if (isSumPresentMemo(arr, sum, n)) {
  //       cout << "Subset with given sum found." << endl;
  // }else{
  //       cout << "No subset with given sum found." << endl;
  // }

  if (isSumPresentTopDown(arr, sum, n)) {
        cout << "Subset with given sum found." << endl;
  }else{
        cout << "No subset with given sum found." << endl;
  }
  return 0;
}
