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

bool isSameTree(Node* root1, Node* root2){
  if(root1 == NULL || root2==NULL)
    return root1 == root2;

  return (root1->data == root2->data) && isSameTree(root1->left, root2->left) && isSameTree(root1->right, root2->right);
}

int main(){
  struct Node*root1 = new Node(1);
  root1->left = new Node(2);
  root1->right = new Node(3);

  root1->left->left = new Node(4);

  struct Node*root2 = new Node(1);
  root2->left = new Node(2);
  root2->right = new Node(3);

  root2->left->left = new Node(4);

  cout<<isSameTree(root1, root2);

  return 0;
}