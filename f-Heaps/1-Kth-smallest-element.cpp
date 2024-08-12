/*
Given an array and a number k where k is smaller than size of array, we need to find the k’th smallest element in the given array. It is given that all array elements are distinct.

Example:
Input: arr[] = {7, 10, 4, 3, 20, 15}
k = 3
Output: 7 . 
*/

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int findKthSmallest(vector<int> v, int k){
  priority_queue<int>maxHeap;
  for(int i = 0; i < v.size(); i++){
    maxHeap.push(v[i]);
    if(maxHeap.size() > k){
      maxHeap.pop();
    }
  }
  return maxHeap.top();
}

int main(){
  vector<int> v = {4,5,2,6,3,7,0,8};
  int k = 3;
  cout<<findKthSmallest(v, k);
  return 0;
}