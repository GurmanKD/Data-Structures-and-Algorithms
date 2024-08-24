#include<iostream>
#include<new>
#include<queue>
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

vector<vector<int>> levelOrder(Node* root){
  
  vector<vector<int>>traversalAns;

  if(root == NULL)
    return traversalAns;
  
  queue<Node*>q;
  q.push(root);

  while(!q.empty()){

    int qSize = q.size();

    vector<int>currLevel;

    for(int i = 0; i < qSize; i++){
      Node* temp = q.front();
      q.pop();

      if(temp->left)
        q.push(temp->left);
      if(temp->right)
        q.push(temp->right);
      
      currLevel.push_back(temp->data);
    }

    traversalAns.push_back(currLevel);
  }
  
  return traversalAns;
}

int main(){
  struct Node*root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);

  root->left->left = new Node(4);

  vector<vector<int>> ans = levelOrder(root);
  for(int i = 0; i<ans.size(); i++){
    for(int j = 0; j < ans[i].size(); j++){
      cout<<ans[i][j]<<" ";
    }
    cout<<endl;
  }
  return 0;
}

