// shortest path in an weighted Directed Acyclic Graphs

// we have to find an array of shortest distance from source node to all other nodes

#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include<queue>
#include<stack>
#include<limits.h>

using namespace std;

void buildAdjacencyList(const vector<pair<pair<int, int>, int>>& edgeList, unordered_map<int, list<pair<int,int>>>& adjacencyList) {
    for (auto& edge : edgeList) {
        int fromVertex = edge.first.first;
        int toVertex = edge.first.second;
        int weight = edge.second;
        adjacencyList[fromVertex].push_back({toVertex, weight});
    }
}

void printAdjacencyList(unordered_map<int, list<pair<int,int>>> adjacencyList) {
    for (auto& vertex : adjacencyList) {
        cout << vertex.first << " -> ";
        for ( auto& neighbor : vertex.second) {
            cout <<"["<< neighbor.first << ", "<<neighbor.second << "],";
        }
        cout << endl;
    }
}

void topoSortHelper(int currentVertex, unordered_map<int, bool> &visited, stack<int>&s, unordered_map<int, list<pair<int,int>>>& adjacencyList) {
    visited[currentVertex] = true;
    for(auto neighbour : adjacencyList[currentVertex]){
      if(!visited[neighbour.first]){
        topoSortHelper(neighbour.first, visited, s, adjacencyList);
      }
    }
    s.push(currentVertex);
}

void getShortestPath(int src, vector<int>&dist, stack<int>&s, unordered_map<int, list<pair<int,int>>>& adjacencyList){
  dist[src]=0;

  while(!s.empty()){
    int top=s.top();
    s.pop();
    if(dist[top]!=INT_MAX){
      for(auto neighbour:adjacencyList[top]){
        if(dist[top]+neighbour.second < dist[neighbour.first]){
          dist[neighbour.first]=dist[top]+neighbour.second;
        }
      }
    }
  }
}

int main() {
    int numVertices = 4; 
    vector<pair<pair<int, int>, int>> edgeList = { {{0, 1}, 5}, {{0, 2},3}, {{1, 2},2}, {{1, 3},6}, {{2, 3},7},{{2, 4},4},{{2, 5},2},{{3, 4},-1},{{4, 5},-2}};

    unordered_map<int, list<pair<int,int>>> adjacencyList;
    buildAdjacencyList(edgeList, adjacencyList);
    printAdjacencyList(adjacencyList);

    unordered_map<int, bool> visited;

    stack<int>s;

    // topological sort
    for(int i=0; i<6; i++){
      if(!visited[i]){
        topoSortHelper(i, visited, s, adjacencyList);
      }
    }

    int src=1;
    vector<int>dist(6, INT_MAX);

    getShortestPath(src, dist, s, adjacencyList);

    cout<<"answer is: ";
    for(int i=0; i<dist.size(); i++){
      cout<<i<<" -> "<<dist[i]<<endl;
    }
    return 0;
}


