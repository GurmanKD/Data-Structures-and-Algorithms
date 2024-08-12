/*
Given an unsorted array and two numbers x and k, find k closest values to x.
Input : arr[] = {10, 2, 14, 4, 7, 6}, x = 5, k = 3 . 
*/

#include<iostream>
#include<queue>
#include<vector>

using namespace std;

vector<int> findKclosest(vector<int>v, int k, int x){
  vector<int>kClosests;
  priority_queue<pair<int, int>>maxHeap; // {abs diff with x, no.}
  // we took max heap because, we need elements with min absolute difference with x to remain in the heap
  // ie, we want to pop the elements with max absolute diff with x(so the should be on the top)
  for(int i=0; i<v.size(); i++){
    maxHeap.push({abs(v[i]-x), v[i]});
    if(maxHeap.size()>k){
      maxHeap.pop();
    }
  }
  for(int i=0; i<k; i++){
    kClosests.push_back(maxHeap.top().second);
    maxHeap.pop();
  }

  return kClosests;
}

int main(){
  vector<int>v = {5,6,7,8,9};
  int k = 3;
  int x = 7;
  vector<int>kClosests = findKclosest(v, k, x);
  for(int i=0; i<kClosests.size(); i++){
    cout<<kClosests[i];
  }
  return 0;
}