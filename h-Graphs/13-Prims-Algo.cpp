#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <limits.h>
#include <set>

using namespace std;

void buildAdjacencyList(const vector<pair<pair<int, int>, int>>& edgeList, unordered_map<int, list<pair<int,int>>>& adjacencyList) {
    for (auto& edge : edgeList) {
        int fromVertex = edge.first.first;
        int toVertex = edge.first.second;
        int weight = edge.second;
        adjacencyList[fromVertex].push_back({toVertex, weight});
        adjacencyList[toVertex].push_back({fromVertex, weight});
    }
}

void printAdjacencyList(const unordered_map<int, list<pair<int,int>>>& adjacencyList) {
    for (auto& vertex : adjacencyList) {
        cout << vertex.first << " -> ";
        for (auto& neighbor : vertex.second) {
            cout << "[" << neighbor.first << ", " << neighbor.second << "], ";
        }
        cout << endl;
    }
}

vector<pair<pair<int, int>, int>> findPrimsMST(int nNodes, int nEdges, const vector<pair<pair<int, int>, int>>& edgeList) {

    // Create adjacency List
    unordered_map<int, list<pair<int,int>>> adjacencyList; // {node, {adjNode, weight}}
    buildAdjacencyList(edgeList, adjacencyList);
    printAdjacencyList(adjacencyList);

    vector<int> key(nNodes, INT_MAX);
    vector<bool> inMST(nNodes, false);
    vector<int> parent(nNodes, -1);

    key[0] = 0;  // Start from vertex 0
    parent[0] = -1;

    for (int i = 0; i < nNodes; i++) {
        // Find the vertex with the minimum key value that is not in MST
        int mini = INT_MAX;
        int u = -1;

        for (int j = 0; j < nNodes; j++) {  // priority queue to further optimise
            if (!inMST[j] && key[j] < mini) {
                mini = key[j];
                u = j;
            }
        }

        // Mark the chosen vertex as included in MST
        inMST[u] = true;

        // Update the key and parent for adjacent vertices of the picked vertex
        for (auto& it : adjacencyList[u]) {
            int neighbour = it.first;
            int weight = it.second;

            if (!inMST[neighbour] && weight < key[neighbour]) {
                parent[neighbour] = u;
                key[neighbour] = weight;
            }
        }
    }
 
    // Construct the MST
    vector<pair<pair<int, int>, int>> mst;
    for (int i = 1; i < nNodes; i++) {  // Should start from 1, not 2
        mst.push_back({{parent[i], i}, key[i]});
    }

    return mst;
}
int main() {
    int numVertices = 6; 
    vector<pair<pair<int, int>, int>> edgeList = {
        {{0, 1}, 5}, {{0, 2}, 3}, {{1, 2}, 2}, {{1, 3}, 6}, 
        {{2, 3}, 7}, {{2, 4}, 4}, {{2, 5}, 2}, {{3, 4}, 1}, {{4, 5}, 2}
    };

    // Find the Minimum Spanning Tree (MST) using Prim's algorithm
    vector<pair<pair<int, int>, int>> mst = findPrimsMST(numVertices, edgeList.size(), edgeList);

    // Print the MST
    cout << "Edges in the Minimum Spanning Tree (MST):" << endl;
    for (const auto& edge : mst) {
        cout << edge.first.first << " -- " << edge.first.second << " (weight: " << edge.second << ")" << endl;
    }

    return 0;
}
