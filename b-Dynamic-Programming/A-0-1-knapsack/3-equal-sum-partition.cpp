#include<iostream>
#include<vector>
#include<stdbool.h>

using namespace std;

static int t[5][12];

bool isSumPresentTopDown(vector<int> arr, int sum, int n){

  // Initialisation
  for(int i = 0; i < n+1; i++){
    for(int j =0; j < sum+1; j++){
      if(j == 0)
        t[i][j] = 1;
      if(i == 0)
        t[i][j] = 0;
    }
  }

  for(int i = 1; i < n+1; i++){
    for(int j =1; j < sum+1; j++){
      if(arr[i-1] <= sum){
        t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][ j];
      }
      else{
        t[i][j] = t[i-1][j];
      }
    }
  }
  return t[n][sum];
}

int main(){
  vector<int> arr = {1, 5, 11, 5};
  int halfSum = 0;

  int n = arr.size();

  for(int i = 0; i < n; i++){
    halfSum+=arr[i];
  }

  halfSum/=2;

  if (isSumPresentTopDown(arr, halfSum, n)) {
        cout << "Array can be partitioned." << endl;
  }else{
        cout << "Arraty can't be p[artitioned." << endl;
  }
  return 0;
}
