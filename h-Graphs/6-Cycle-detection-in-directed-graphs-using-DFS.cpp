#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
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

bool detectCycleDFS(int currentVertex, const unordered_map<int, list<int>>& adjacencyList, unordered_map<int, bool>& visited, unordered_map<int, bool>& DFSvisited) {
    visited[currentVertex] = true;
    DFSvisited[currentVertex] = true;

    if (adjacencyList.find(currentVertex) != adjacencyList.end()) {
        for (const auto& neighbor : adjacencyList.at(currentVertex)) {
            if (!visited[neighbor]) {
                if (detectCycleDFS(neighbor, adjacencyList, visited, DFSvisited)) {
                    return true;
                }
            } else if (DFSvisited[neighbor] == true) {
                return true;
            }
        }
    }

    DFSvisited[currentVertex] = false;
    return false;
}

bool isCycleInGraph(int numVertices, const vector<pair<int, int>>& edgeList) {
    unordered_map<int, list<int>> adjacencyList;
    buildAdjacencyList(edgeList, adjacencyList);
    printAdjacencyList(adjacencyList);

    unordered_map<int, bool> visited;
    unordered_map<int, bool> DFSvisited;

    // Check for cycles in all connected components
    for (int vertex = 0; vertex < numVertices; vertex++) {
        if (!visited[vertex]) {
            if (detectCycleDFS(vertex, adjacencyList, visited, DFSvisited)) {
                cout << "Cycle is present" << endl;
                return true;
            }
        }
    }
    cout << "Cycle is not present" << endl;
    return false;
}

int main() {
    int numVertices = 4; 
    vector<pair<int, int>> edgeList = { {1, 0}, {0, 3}, {2, 3}, {1, 2} };
    isCycleInGraph(numVertices, edgeList);
    return 0;
}
