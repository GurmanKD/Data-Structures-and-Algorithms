/*
Given an undirected and disconnected graph G(V, E), containing 'V' vertices and 'E' edges, the information about edges is given using 'GRAPH' matrix, where i-th edge is between GRAPH[i][0] and GRAPH[i][1]. 
Print its DFS traversal.
*/

// time and space complexity: linear

#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

void prepareAdjList(vector<pair<int, int>>edgesList, unordered_map<int, list<int>>&adjL){
  for(auto i:edgesList){
    int u = i.first;
    int v = i.second;
    adjL[u].push_back(v);
    adjL[v].push_back(u);
  }
}

void printAdjList(unordered_map<int, list<int>> & adjL){
  for(auto i:adjL){
    cout<<i.first<<"->";
    for(auto j:i.second){
      cout<<j<<", ";
    }
    cout<<endl;
  }
}

// if you require answer in sorted order use set instead of list because set by default stores in sorted order
void dfsHelper(unordered_map<int, list<int>> & adjL, unordered_map<int, bool> &visited, vector<int> &DFStraversal, int nodeIndex){
  visited[nodeIndex]=true;
  DFStraversal.push_back(nodeIndex);
  for(auto i:adjL[nodeIndex]){
    if(visited[i] != true){
      dfsHelper(adjL, visited, DFStraversal, i);
    }
  }
}


vector<int>DFS(int vertex, vector<pair<int, int>>edgesList){

  unordered_map<int, list<int>>adjL;
  prepareAdjList(edgesList, adjL);
  printAdjList(adjL);

  vector<int>DFStraversal; // stores answer
  unordered_map<int, bool>visited;

  for(int i = 0; i < vertex; i++){
    if(!visited[i]){
      dfsHelper(adjL, visited, DFStraversal, i);
    }
  }
  return DFStraversal;
}

int main(){
  int vertex = 5;
  vector<pair<int, int>>edgesList={{4, 4}, {0, 1}, {0, 3}, {1, 2}, {2, 3}};
  vector<int> DFStraversal=DFS(vertex, edgesList);
  cout<<"DFS traversal: ";
  for(int i = 0; i < DFStraversal.size(); i++){
    cout<<DFStraversal[i]<<" ";
  }
  cout<<endl;
  return 0;
}
