#include<iostream>
#include<new>
#include<queue>
#include<map>
#include<set>
using namespace std;

struct Node{
  int data;
  struct Node* left;
  struct Node* right;

  Node(int val){
    data = val;
    left = right = NULL;
  }
};

vector<vector<int>> verticalTraversal(Node*root){
  map<int, map<int, multiset<int>>> nodes;// {vlevel, {hlevel, node on that v/h}}
  // multiset because there can be 2 same nodes overlapping and set would only keep unique values
  queue<pair<Node*, pair<int, int>>> todoQ; // {node, {hLevel, vLevel}}

  todoQ.push({root, {0,0}});
  while(!todoQ.empty()){
    auto p = todoQ.front();
    todoQ.pop();
    Node* node = p.first;
    int x = p.second.first, y = p.second.second;
    nodes[x][y].insert(node->data);
    if(node->left)
      todoQ.push({node->left, {x-1, y+1}});
    if(node->right)
      todoQ.push({node->right, {x+1, y+1}});
  }
  vector<vector<int>>ans;
  for(auto p : nodes){
    vector<int>col;
    for(auto q : p.second){
      col.insert(col.end(), q.second.begin(), q.second.end());
    }
    ans.push_back(col);
  }
  return ans;
}

int main(){
  struct Node*root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);

  root->left->left = new Node(4);

  vector<vector<int>> ans = verticalTraversal(root);
  for(int i=0; i<ans.size(); i++){
    for(int j=0; j<ans[i].size(); j++){
      cout<<ans[i][j]<<" ";
    }
    cout<<endl;
  }


  return 0;
}