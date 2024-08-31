#include<iostream>
#include<vector>
#include<new>
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

bool findPathHelper(Node* root, vector<int>&path, int key){
  if(!root)
    return false;

  path.push_back(root->data);

  if(root->data == key)
    return true;

  if(findPathHelper(root->left, path, key)||findPathHelper(root->right, path, key)){
    return true;
  }
  
  path.pop_back();
  return false;
}

vector<int>findPath(Node*root, int key){
  vector<int>ans;
  if(root==NULL)return ans;
  findPathHelper(root, ans, 4);
  return ans;
}

int main(){
  struct Node*root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);

  root->left->left = new Node(4);

  vector<int>ans=findPath(root, 4);

  for(int i=0; i<ans.size(); i++){
    cout<<ans[i]<<" ";
  }
  return 0;
}