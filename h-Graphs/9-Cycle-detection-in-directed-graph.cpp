/*
We know that, we can find topological sort only for Directed Acyclic Graphs (DAGS)

ie, if we are able to find a topological sort, the graph is an acyclic graph.
*/

// Applying Kahn's Algorithm:

#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include<queue>
using namespace std;

void buildAdjacencyList(const vector<pair<int, int>>& edgeList, unordered_map<int, list<int>>& adjacencyList) {
    for (const auto& edge : edgeList) {
        int fromVertex = edge.first;
        int toVertex = edge.second;
        adjacencyList[fromVertex].push_back(toVertex);
    }
}

void printAdjacencyList(const unordered_map<int, list<int>>& adjacencyList) {
    for (const auto& vertex : adjacencyList) {
        cout << vertex.first << " -> ";
        for (const auto& neighbor : vertex.second) {
            cout << neighbor << ", ";
        }
        cout << endl;
    }
}

void buildIndegreeList(const unordered_map<int, list<int>>& adjacencyList, unordered_map<int, int>&inDegree){
  for (const auto& vertex : adjacencyList) {
    for (const auto& neighbour : vertex.second) {
        inDegree[neighbour]++;
    }
  }
}

vector<int> topologicalSort(const int numVertices, const vector<pair<int, int>>& edgeList) {
    unordered_map<int, list<int>> adjacencyList;
    buildAdjacencyList(edgeList, adjacencyList);
    printAdjacencyList(adjacencyList);

    unordered_map<int, int> inDegree;
    buildIndegreeList(adjacencyList, inDegree);

    queue<int> q;

    // 0 indegree walo ko push kardo
    for (int vertex = 0; vertex < numVertices; vertex++) {
        if (inDegree[vertex]==0) {
            q.push(vertex);
        }
    }

    // do bfs
    vector<int>ans;
    while(!q.empty()){
      int frontNode = q.front();
      q.pop();

      ans.push_back(frontNode);
      
      // neighbour's indegree update
      for(auto neighbour:adjacencyList[frontNode]){
        inDegree[neighbour]--;
        if(inDegree[neighbour] == 0){
          q.push(neighbour);
        }
      }
    }
    return ans;
}

int main() {
    int numVertices = 4; 
    vector<pair<int, int>> edgeList = { {0, 1}, {1, 2}, {2, 3}, {3, 0} };
    vector<int>ans = topologicalSort(numVertices, edgeList);
    if(ans.size()<numVertices) cout<<"The graph is Cyclic.";
    else cout<<"The graph is Acyclic.";
    return 0;
}


