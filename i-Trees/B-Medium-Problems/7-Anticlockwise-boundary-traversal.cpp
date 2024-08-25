// left boundary excluding leaf
// leaf nodes
// right boundary in reverse excluding leaf

#include<iostream>
#include<new>
#include<vector>
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

bool isLeaf(Node* node){
  if(!node->left && !node->right)
    return true;
  return false;
}

void addLeftBoundary(Node* root, vector<int>&result){
  Node* curr = root->left;
  while(curr){
    if(!isLeaf(curr))
      result.push_back(curr->data);
    if(curr->left)
      curr = curr->left;
    else  
      curr = curr->right;
  }
}

void addRightBoundary(Node* root, vector<int>&result){
  Node* curr = root->right;
  vector<int> temp;
  while(curr){
    if(!isLeaf(curr))
      temp.push_back(curr->data);
    if(curr->right)
      curr = curr->right;
    else  
      curr = curr->left;
  }
  for(int i=temp.size()-1; i>=0; i--){
    result.push_back(temp[i]);
  }
}

void addLeaves(Node* root, vector<int>&result){
  if(isLeaf(root)){
    result.push_back(root->data);
    return;
  }
  if(root->left)addLeaves(root->left, result);
  if(root->right)addLeaves(root->right, result);
}

vector<int> boundary(Node*root){
  vector<int>result;
  if(!root)return result;
  if(!isLeaf(root))
    result.push_back(root->data);
    addLeftBoundary(root, result);
    addLeaves(root, result);
    addRightBoundary(root, result);
    return result;
}

int main(){
  struct Node*root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);

  root->left->left = new Node(4);

  vector<int>ans=boundary(root);
  for(int i=0; i<ans.size(); i++){
    cout<<ans[i]<<" ";
  }

  return 0;
}