/*
Write an efficient program for printing k largest elements in an array. Elements in array can be in any order.

For example, if given array is [1, 23, 12, 9, 30, 2, 50] and you are asked for the largest 3 elements i.e., k = 3 then your program should print 50, 30 and 23. . 
*/

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector<int> findKLargest(vector<int> v, int k){
  priority_queue<int, vector<int>, greater<int>>minHeap;
  for(int i = 0; i < v.size(); i++){
    minHeap.push(v[i]);
    if(minHeap.size() > k){
      minHeap.pop();
    }
  }
  vector<int>kLargests;
  for(int i=0; i<k; i++){
    kLargests.push_back(minHeap.top());
    minHeap.pop();
  }
  
  return kLargests;
}

int main(){
  vector<int> v = {4,5,2,6,3,7,0,8};
  int k = 3;
  vector<int>kLargests=findKLargest(v, k);
  for(int i=0; i<k; i++){
    cout<<kLargests[i];
  }
  return 0;
}
