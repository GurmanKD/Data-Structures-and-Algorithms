/*
You are given an __undirected__ and __disconnected__ graph G(V, E) having V vertices numbered from 0 to V-1 and E edges. Your task is to print its BFS traversal starting from the Oth vertex.

BFS or Breadth-First Traversal of a graph is an algorithm used to visit all of the nodes of a given graph. In this traversal algorithm, one node is selected, and then all of the adjacent nodes are visited one by one.

An undirected graph is a graph where all the edges are bidirectional, i.e., they point from source to destination and destination to source.

A graph is disconnected if at least two vertices of the graph are not connected by a path.
*/

/*
time complexity: O(n+e)
space complexity: O(n+e)
*/

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
void bfsHelper(unordered_map<int, list<int>> & adjL, unordered_map<int, bool> &visited, vector<int> &BFStraversal, int nodeIndex){
  queue<int>q;
  q.push(nodeIndex);
  visited[nodeIndex]=true;
  BFStraversal.push_back(nodeIndex);
  while(!q.empty()){
    int front = q.front();
    q.pop();
    for(auto i:adjL[front]){
      if(visited[i] != true){
        q.push(i);
        visited[i] = true;
        BFStraversal.push_back(i);
      }
    }
  }
}


vector<int>BFS(int vertex, vector<pair<int, int>>edgesList){

  unordered_map<int, list<int>>adjL;
  prepareAdjList(edgesList, adjL);
  printAdjList(adjL);

  vector<int>BFStraversal; // stores answer
  unordered_map<int, bool>visited;

  for(int i = 0; i < vertex; i++){
    if(!visited[i]){
      bfsHelper(adjL, visited, BFStraversal, i);
    }
  }
  return BFStraversal;
}

int main(){
  int vertex = 5;
  vector<pair<int, int>>edgesList={{4, 4}, {0, 1}, {0, 3}, {1, 2}, {2, 3}};
  vector<int> BFStraversal=BFS(vertex, edgesList);
  cout<<"BFS traversal: ";
  for(int i = 0; i < BFStraversal.size(); i++){
    cout<<BFStraversal[i]<<" ";
  }
  cout<<endl;
  return 0;
}
