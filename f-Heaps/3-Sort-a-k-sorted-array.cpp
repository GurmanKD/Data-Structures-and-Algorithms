/*
Given an array of n elements, where each element is at most k away from its target position, devise an algorithm that sorts in O(n log k) time. For example, let us consider k is 2, an element at index 7 in the sorted array, can be at indexes 5, 6, 7, 8, 9 in the given array.

Example:
Input : arr[] = {6, 5, 3, 2, 8, 10, 9}
k = 3 
Output : arr[] = {2, 3, 5, 6, 8, 9, 10} . 
*/

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector<int>sortKsorted(vector<int>v, int k){
  vector<int>sortedArr;
  priority_queue<int, vector<int>, greater<int>> minHeap;
  for(int i = 0; i < v.size(); i++){
    minHeap.push(v[i]);
    if(minHeap.size()>k+1){
      sortedArr.push_back(minHeap.top());
      minHeap.pop();
    }
  }
  for(int i=0; i<k+1; i++){
    sortedArr.push_back(minHeap.top());
    minHeap.pop();
  }
  return sortedArr;
}

int main(){
  vector<int>v = {6,5,3,2,8,10,9};
  int k = 3;
  vector<int>sortedArr = sortKsorted(v, k);
  for(int i=0; i<v.size(); i++){
    cout<<sortedArr[i];
  }
  return 0;
} 