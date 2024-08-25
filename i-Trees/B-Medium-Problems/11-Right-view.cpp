#include<iostream>
#include<new>
#include<vector>
#include<queue>
#include<map>
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

void rightView(Node*root, int level, vector<int>&ans){
  
  if(root==NULL)
    return;

  if(ans.size()==level)
    ans.push_back(root->data);
  
  rightView(root->right, level+1, ans);
  rightView(root->left, level+1, ans);
}


int main(){
  struct Node*root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);

  root->left->left = new Node(4);

  vector<int>ans;
  rightView(root, 0, ans);

  for(int i=0; i<ans.size(); i++){
    cout<<ans[i]<<" ";
  }
  return 0;
}