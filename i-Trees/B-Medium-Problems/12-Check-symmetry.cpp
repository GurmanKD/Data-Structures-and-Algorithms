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

bool isSymmetric(Node* left, Node* right){
  if(left==NULL || right==NULL)
    return left==right;
  if(left->data != right->data)
    return false;

  return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
}

int main(){
  struct Node*root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(2);

  cout<<isSymmetric(root->left, root->right);

  return 0;
}