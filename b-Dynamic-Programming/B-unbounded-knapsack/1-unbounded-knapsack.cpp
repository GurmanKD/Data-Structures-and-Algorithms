#include<iostream>
#include<vector>
#include <cstring> // for memset

using namespace std;

int recursiveSolve(vector<int> value, vector<int> weight, int capacity, int n){

  // no element left in array or knaqpsack is full
  if(n == 0 || capacity == 0){
    return 0;
  }

  if(weight[n-1] <= capacity){
    return max(

      // include
      value[n-1]+recursiveSolve(value, weight, capacity-weight[n-1], n), 

      // not include
    recursiveSolve(value, weight, capacity, n-1));
  }
  
  else if(weight[n-1] > capacity){
    // not include
    return recursiveSolve(value, weight, capacity, n-1);
  }
}

int static t1[5][8];

int memoSolve(vector<int> value, vector<int> weight, int capacity, int n){

  if(n == 0 || capacity == 0){
    return 0;
  }

  if(t1[n][capacity] != -1)
    return t1[n][capacity];

  if(weight[n-1] <= capacity){
    return t1[n][capacity] = max(
      value[n-1]+memoSolve(value, weight, capacity-weight[n-1], n), 
      memoSolve(value, weight, capacity, n-1));
  }
  
  else if(weight[n-1] > capacity){
    return t1[n][capacity] = memoSolve(value, weight, capacity, n-1);
  }

}

int static t2[5][8];

int topDownSolve(vector<int> value, vector<int> weight, int capacity, int n){

  // base condition => initialization
  for(int i = 0; i < n+1; i++){
    for(int j = 0; j < capacity+1; j++){
      if(i == 0 || j == 0){
        t2[i][j] = 0;
      }
    }
  }

  for(int i = 0; i < n+1; i++){
    for(int j = 0; j < capacity+1; j++){
      if(weight[i-1] < j){
        t2[i][j] = max(value[i-1]+t2[i][j-weight[i-1]], t2[i-1][j]);
      }else{
        t2[i][j] = t2[i-1][j];
      }
    }
  }

  return t2[n][capacity];
}

int main(){

  memset(t1, -1, sizeof(t1));

  vector<int> value = {10,4,5,7};
  vector<int> weight = {1,3,4,5};
  int capacity = 7;

  cout<<recursiveSolve(value, weight, capacity, 4);

  cout<<memoSolve(value, weight, capacity, 4);

  cout<<topDownSolve(value, weight, capacity, 4);
}