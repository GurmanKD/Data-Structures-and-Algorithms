#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>

typedef std::pair<int, int> pii;

using namespace std;

vector<int> findKmostFreq(vector<int>v, int k){
  vector<int>kMostFreq;
  priority_queue<pii, vector<pii>, greater<pii>>minHeap; // {freq, no.}
  // we took min heap because, we need elements with max frequency to remain in the heap
  // ie, we want to pop the elements with min frequency (so the min should be on the top)
  unordered_map<int, int>freqMap;
  for(int i=0; i<v.size(); i++){
    freqMap[v[i]]++;
  }
  for(auto i=freqMap.begin(); i!=freqMap.end(); i++){
    minHeap.push({i->second, i->first});
    if(minHeap.size()>k){
      minHeap.pop();
    }
  }
  while(minHeap.size()!=0){
    kMostFreq.push_back(minHeap.top().second);
    minHeap.pop();
  }
  return kMostFreq;
}

int main(){
  vector<int>v = {1,1,1,2,2,3,3,4,5};
  int k = 3;
  int x = 7;
  vector<int>kMostFreq = findKmostFreq(v, k);
  for(int i=0; i<kMostFreq.size(); i++){
    cout<<kMostFreq[i];
  }
  return 0;
}