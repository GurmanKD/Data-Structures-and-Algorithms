/*
TOPOLOGICAL SORT: Linear ordering of vertices such that for every edge u->v, u appears before v.
only for DAG(directed acyclic graph) 
DFS karo, jab bhi koi recursive call wapis jaae tab use stack me daal do
kyoki recursive call wapis jaa rhi hai matlab, ab us vertex se aage jaana possible nhi hai
*/

#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include<stack>
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

// you can also use a vector visited instead of unordered map to further improve the time complexity
void topoSortHelper(int currentVertex, unordered_map<int, bool> &visited, stack<int>&s, unordered_map<int, list<int>>& adjacencyList) {
    visited[currentVertex] = true;
    for(auto neighbour : adjacencyList[currentVertex]){
      if(!visited[neighbour]){
        topoSortHelper(neighbour, visited, s, adjacencyList);
      }
    }
    s.push(currentVertex);
}

vector<int> topologicalSort(const int numVertices, const vector<pair<int, int>>& edgeList) {
    unordered_map<int, list<int>> adjacencyList;
    buildAdjacencyList(edgeList, adjacencyList);
    printAdjacencyList(adjacencyList);

    unordered_map<int, bool> visited;
    stack<int>s;

    // Check for cycles in all connected components
    for (int vertex = 0; vertex < numVertices; vertex++) {
        if (!visited[vertex]) {
            topoSortHelper(vertex, visited, s, adjacencyList);
        }
    }
    vector<int>ans;
    while(!s.empty()){
      ans.push_back(s.top());
      s.pop();
    }
    return ans;
}

int main() {
    int numVertices = 4; 
    vector<pair<int, int>> edgeList = { {0, 1}, {0, 3}, {2, 3} };
    vector<int>ans = topologicalSort(numVertices, edgeList);
    for(int i=0; i<ans.size(); i++){
      cout<< ans[i]<<" ";
    }
    return 0;
}


