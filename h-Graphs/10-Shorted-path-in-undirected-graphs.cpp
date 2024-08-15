// shortest path in an unweighted graph

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
        adjacencyList[toVertex].push_back(fromVertex);
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

vector<int> shortestPath(const int numVertices, const vector<pair<int, int>>& edgeList, int srcNode, int destNode) {
    unordered_map<int, list<int>> adjacencyList;
    buildAdjacencyList(edgeList, adjacencyList);
    printAdjacencyList(adjacencyList);

    // do BFS
    unordered_map<int, int> parent;
    parent[srcNode]=-1;
    unordered_map<int, int> visited;

    queue<int> q;
    q.push(srcNode);
    visited[srcNode]=true;

    while(!q.empty()){
      int frontNode = q.front();
      q.pop();
      
      // neighbour's indegree update
      for(auto neighbour:adjacencyList[frontNode]){
        if(!visited[neighbour]){
          visited[neighbour]=true;
          parent[neighbour]=frontNode;
          q.push(neighbour);
        }
      }
    }
    
    // prepare shortest path
    vector<int>ans;
    ans.push_back(destNode);
    int currNode = destNode;
    while(currNode!=srcNode){
      currNode=parent[currNode];
      ans.push_back(currNode);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    int numVertices = 4; 
    vector<pair<int, int>> edgeList = { {0, 1}, {1, 2}, {2, 3}, {3, 0} };
    vector<int>ans = shortestPath(numVertices, edgeList, 0, 2);
    for(int i=0; i<ans.size(); i++){
      cout<<ans[i]<<" ";
    }
    return 0;
}


