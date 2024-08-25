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

vector<int> bottomView(Node*root){
  vector<int>ans;
  if(root==NULL)return ans;
  map<int, int>mp; // sorted in inc. order by default
  queue<pair<Node*, int>>q;
  q.push({root, 0});
  while(!q.empty()){
    auto temp = q.front();
    q.pop();
    Node* tempNode = temp.first;
    int tempCol = temp.second;
    mp[tempCol]=tempNode->data; // only this line is different
    if(tempNode->left){
      q.push({tempNode->left, tempCol-1});
    }
    if(tempNode->right){
      q.push({tempNode->right, tempCol+1});
    }
  }

  for(auto it:mp){
    ans.push_back(it.second);
  }

  return ans;
}


int main(){
  struct Node*root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);

  root->left->left = new Node(4);

  vector<int>ans = bottomView(root);

  for(int i=0; i<ans.size(); i++){
    cout<<ans[i]<<" ";
  }

  return 0;
}