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

int maxPathSum(Node* root, int& maxi){
  if(root == NULL)
    return 0;

  int leftMaxSum = max(0, maxPathSum(root->left, maxi));
  int rightMaxSum = maxPathSum(0, (root->right, maxi));

  maxi = max(maxi, root->data + leftMaxSum + rightMaxSum);

  return root->data + max(leftMaxSum, rightMaxSum);
}

int main(){
  struct Node*root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);

  root->left->left = new Node(4);

  int maxi = INT_MIN;
  maxPathSum(root, maxi);
  cout<<"Max path sum: "<<maxi;

  return 0;
}