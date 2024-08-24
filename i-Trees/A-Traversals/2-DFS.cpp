// DFS is of 3 tytpes: inorder, preorder, postorder

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

void preorderDFS(Node* node){
  if(node == NULL)
    return;

  cout<< node->data<<" ";
  preorderDFS(node->left);
  preorderDFS(node->right);
}

void inorderDFS(Node* node){
  if(node == NULL)
    return;

  inorderDFS(node->left);
  cout<< node->data<<" ";
  inorderDFS(node->right);
}

void postorderDFS(Node* node){
  if(node == NULL)
    return;

  postorderDFS(node->left);
  postorderDFS(node->right);
  cout<< node->data<<" ";
}

int main(){
  struct Node*root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);

  root->left->left = new Node(4);

  cout<<"preorder traversal:"<<endl;
  preorderDFS(root);
  cout<<endl;

  cout<<"inorder traversal:"<<endl;
  inorderDFS(root);
  cout<<endl;

  cout<<"postorder traversal:"<<endl;
  postorderDFS(root);
  cout<<endl;

  return 0;
}

