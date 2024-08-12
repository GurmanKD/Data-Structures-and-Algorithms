/*
Print the elements of an array in the increasing frequency if 2 numbers have same frequency then print the one which came first.

Example:
Input : arr[] = {2, 5, 2, 8, 5, 6, 8, 8}
Output : arr[] = {8, 8, 8, 2, 2, 5, 5, 6} . 
*/

#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>

typedef std::pair<int, int> pii;

using namespace std;

vector<int> freqSort(vector<int>v){
  vector<int>freqSorted;
  priority_queue<pii>maxHeap; // {freq, no.}
  // min or max any would work, as we do not need to pop anything, if we use min, we wll have to return reverse of the kMostFreq
  unordered_map<int, int>freqMap;
  for(int i=0; i<v.size(); i++){
    freqMap[v[i]]++;
  }
  for(auto i=freqMap.begin(); i!=freqMap.end(); i++){
    maxHeap.push({i->second, i->first});
  }
  while(maxHeap.size()!=0){
    for(int i=0; i<maxHeap.top().first; i++){
      freqSorted.push_back(maxHeap.top().second);
    }
    maxHeap.pop();
  }
  return freqSorted;
}

int main(){
  vector<int>v = {1,4,1,2,2,3,3,1,2,2,2,5};
  vector<int>freqSorted = freqSort(v);
  for(int i=0; i<freqSorted.size(); i++){
    cout<<freqSorted[i];
  }
  return 0;
}