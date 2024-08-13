#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

void prepareAdjList(vector<pair<int, int>>edgesList, unordered_map<int, list<int>>&adjL){
  for(auto i:edgesList){
    int u = i.first; // or int u = i[0]; 
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

bool isCyclicBFS(int srcNode, unordered_map<int, list<int>> adjL, unordered_map<int, bool>&visited){
  unordered_map<int, int> parent;

  parent[srcNode] = -1;
  visited[srcNode] = true;

  queue<int>q;
  q.push(srcNode);

  while(!q.empty()){
     int frontNode = q.front();
     q.pop();
     for(auto i:adjL[frontNode]){
      if(visited[i] == true && i != parent[frontNode]) {
        return true;
      }
      else if(visited[i] != true){
        q.push(i);
        visited[i] = true;
        parent[i] = frontNode;
      }
    }
  }
  return false;
}

bool cycleDetection(int vertex, vector<pair<int, int>>edgesList){
  // create adjacency list
  unordered_map<int, list<int>> adjL;
  prepareAdjList(edgesList, adjL);
  printAdjList(adjL);

  unordered_map<int, bool>visited;

  // to handle disconnected components
  for(int i=0; i<vertex; i++){
    if(visited[i]!=true){
      bool ans = isCyclicBFS(i, adjL, visited);
      if(ans == 1){
        cout<<"Cycle is present";
        return true;
      }
    }
  }
  cout<<"Cycle is not present";
  return false;
}

int main(){
  int vertex = 3;
  vector<pair<int, int>>edgesList={{0, 1}, {0, 3}, {2, 3}};
  cycleDetection(vertex, edgesList);
  return 0;
}
