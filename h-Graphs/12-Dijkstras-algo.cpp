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

vector<int> dijkstras(int src, vector<int>& dist, set<pair<int, int>>& st, const unordered_map<int, list<pair<int,int>>>& adjacencyList){
    dist[src] = 0;
    st.insert({0, src});

    while (!st.empty()) {
        // fetch the top record
        auto top = *(st.begin());

        int topNodeDist = top.first;
        int topNode = top.second;

        // remove the top record
        st.erase(st.begin());

        // traverse on neighbours
        for (auto& neighbour : adjacencyList.at(topNode)) {
            if (topNodeDist + neighbour.second < dist[neighbour.first]) {
                auto record = st.find({dist[neighbour.first], neighbour.first});

                // if you find record, erase it
                if (record != st.end()) {
                    st.erase(record);
                }

                // update distance
                dist[neighbour.first] = topNodeDist + neighbour.second;
                st.insert({dist[neighbour.first], neighbour.first});
            }
        }
    }
    return dist;
}

int main() {
    int numVertices = 6; 
    vector<pair<pair<int, int>, int>> edgeList = {
        {{0, 1}, 5}, {{0, 2}, 3}, {{1, 2}, 2}, {{1, 3}, 6}, 
        {{2, 3}, 7}, {{2, 4}, 4}, {{2, 5}, 2}, {{3, 4}, 1}, {{4, 5}, 2}
    };

    unordered_map<int, list<pair<int,int>>> adjacencyList;
    buildAdjacencyList(edgeList, adjacencyList);
    printAdjacencyList(adjacencyList);

    vector<int> dist(numVertices, INT_MAX);
    set<pair<int, int>> st;

    vector<int> ans = dijkstras(0, dist, st, adjacencyList);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}
