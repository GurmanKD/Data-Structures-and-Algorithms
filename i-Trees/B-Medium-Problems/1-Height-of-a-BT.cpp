// OR max depth of a BT

// worst case tc O(n), sc O(n) (=>skew)
#include<iostream>
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

int findHeight(Node* root){
  if(root == NULL)
    return 0;

  int height = 1+ max(findHeight(root->left), findHeight(root->right));

  return height;
}

int main(){
  struct Node*root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);

  root->left->left = new Node(4);

  int height = findHeight(root);

  cout<<"height is: "<<height<<endl;
  return 0;
}