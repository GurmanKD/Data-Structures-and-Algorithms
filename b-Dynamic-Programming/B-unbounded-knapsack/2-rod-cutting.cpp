/*
Given a rod of length n inches and an array of prices that includes prices of all pieces of size smaller than n. Determine the maximum value obtainable by cutting up the rod and selling the pieces. For example, if the length of the rod is 8 and the values of different pieces are given as the following, then the maximum obtainable value is 22 (by cutting in two pieces of lengths 2 and 6) 

length   | 1   2   3   4   5   6   7   8  
--------------------------------------------
price    | 1   5   8   9  10  17  17  20

or specific lengths

----exactly same as previous----
*/

#include<iostream>
#include<vector>
#include <cstring> // for memset

using namespace std;

int recursiveSolve(vector<int> value, vector<int> length, int totalLength, int n){

  // no element left in array or knaqpsack is full
  if(n == 0 || totalLength == 0){
    return 0;
  }

  if(length[n-1] <= totalLength){
    return max(

      // include
      value[n-1]+recursiveSolve(value, length, totalLength-length[n-1], n), 

      // not include
    recursiveSolve(value, length, totalLength, n-1));
  }
  
  else if(length[n-1] > totalLength){
    // not include
    return recursiveSolve(value, length, totalLength, n-1);
  }
}

int static t1[5][8];

int memoSolve(vector<int> value, vector<int> length, int totalLength, int n){

  if(n == 0 || totalLength == 0){
    return 0;
  }

  if(t1[n][totalLength] != -1)
    return t1[n][totalLength];

  if(length[n-1] <= totalLength){
    return t1[n][totalLength] = max(
      value[n-1]+memoSolve(value, length, totalLength-length[n-1], n), 
      memoSolve(value, length, totalLength, n-1));
  }
  
  else if(length[n-1] >totalLength){
    return t1[n][totalLength] = memoSolve(value, length, totalLength, n-1);
  }

}

int static t2[5][8];

int topDownSolve(vector<int> value, vector<int> length, int totalLength, int n){

  // base condition => initialization
  for(int i = 0; i < n+1; i++){
    for(int j = 0; j < totalLength+1; j++){
      if(i == 0 || j == 0){
        t2[i][j] = 0;
      }
    }
  }

  for(int i = 0; i < n+1; i++){
    for(int j = 0; j < totalLength+1; j++){
      if(length[i-1] < j){
        t2[i][j] = max(value[i-1]+t2[i][j-length[i-1]], t2[i-1][j]);
      }else{
        t2[i][j] = t2[i-1][j];
      }
    }
  }

  return t2[n][totalLength];
}

int main(){

  memset(t1, -1, sizeof(t1));

  vector<int> value = {10,4,5,7};
  vector<int> length = {1,3,4,5};
  int totalLength = 7;

  cout<<recursiveSolve(value, length, totalLength, 4);

  cout<<memoSolve(value, length, totalLength, 4);

  cout<<topDownSolve(value, length, totalLength, 4);
}