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

// tc: O(n^2)
int findDia(Node* root, int maxi){
  if(root == NULL)
    return 0;
  int lh = findHeight(root->left);
  int rh = findHeight(root->right);

  maxi = max(maxi, lh+rh);

  findDia(root->left, maxi);
  findDia(root->right, maxi);

  return maxi;
}

// optimised solution; tc: O(n) => modify find height
int optimisedFindDia(Node* root, int maxi){
  if(root == NULL)
    return 0;
  int lh = optimisedFindDia(root->left, maxi);
  int rh = optimisedFindDia(root->right, maxi);

  maxi = max(maxi, lh+rh);

  return 1+max(lh, rh);
}

int main(){
  struct Node*root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);

  root->left->left = new Node(4);

  cout<<"dia is: "<<findDia(root, INT_MIN)<< endl;
  cout<<"dia is: "<<optimisedFindDia(root, INT_MIN);

  return 0;
}