#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

template <typename T>

class graph{
  public:
    unordered_map<T, list<T>>adjacencyList;

    void addEdge(int u, int v, bool isDirectedEdge){
      adjacencyList[u].push_back(v);
      if(isDirectedEdge == 0){
        adjacencyList[v].push_back(u);
      }
    }

    void printAdjList(){
      for(auto i:adjacencyList){
        cout<<i.first<<"->";
        for(auto j:i.second){
          cout<<j<<", ";
        }
        cout<<endl;
      }
    }
};

int main(){
  int nNodes = 3;
  int nEdges = 3;

  graph<int> g;

  for(int i=0; i<nEdges; i++){
    int u, v;
    cin>>u>>v;
    g.addEdge(u, v, 0); // undirected graph
  }

  g.printAdjList();

  return 0;
}
