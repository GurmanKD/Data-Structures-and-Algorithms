/*
Given an unsorted array and two numbers x and k, find k closest values to x.
Input : arr[] = {10, 2, 14, 4, 7, 6}, x = 5, k = 3 . 
*/

#include<iostream>
#include<queue>
#include<vector>

using namespace std;

vector<pair<int, int>> findKclosest(vector<pair<int, int>>points, int k){
  vector<pair<int, int>>kClosests;
  priority_queue<pair<float, pair<int, int>>>maxHeap; // {abs diff with x, no.}
  // we took max heap because, we need elements with min distance with the origin to remain in the heap
  // ie, we want to pop the elements with max distance (so, the max should be on the top)
  for(int i=0; i<points.size(); i++){
    float dist=sqrt(pow(points[i].first, 2)+pow(points[i].second, 2));
    // even if we dont take sqrt, the relative order will remain same
    maxHeap.push({dist, points[i]});
    if(maxHeap.size()>k){
      maxHeap.pop();
    }
  }
  while(maxHeap.size()>0){
    kClosests.push_back(maxHeap.top().second);
    maxHeap.pop();
  }
  return kClosests;
}

int main(){
  vector<pair<int, int>>points = {{1,2}, {3,4}, {0,0}};
  int k = 2;
  vector<pair<int, int>>kClosests = findKclosest(points, k);
  for(int i=0; i<kClosests.size(); i++){
    cout<<kClosests[i].first<<" "<<kClosests[i].second<<endl;
  }
  return 0;
}