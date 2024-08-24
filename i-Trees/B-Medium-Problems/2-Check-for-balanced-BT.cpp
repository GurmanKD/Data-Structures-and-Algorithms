// OR max depth of a BT

// worst case tc O(n)*O(n) = O(n^2), sc O(n) (=>skew)
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

bool isBalanced(Node* root){
  if(root == NULL)
    return true;

  int leftH = findHeight(root->left);
  int rightH = findHeight(root->right);

  if(abs(leftH-rightH)>1)
    return false;

  bool isLeftBalanced = isBalanced(root->left);
  bool isRightBalanced = isBalanced(root->right);

  if(!(isLeftBalanced && isRightBalanced)) 
    return false;
  
  return true;
}

// tc = O(n) solution
// return height if balanced, -1 otherwise
int isBalancedOptimised(Node* node){
  if(node == NULL)
    return 0;
  int lh=isBalancedOptimised(node->left);
  int rh=isBalancedOptimised(node->right);
  if(rh==-1 || lh==-1)
    return -1;
  if(abs(lh-rh)>1)
    return -1;
  return max(lh, rh)+1;
}

int main(){
  struct Node*root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);

  root->left->left = new Node(4);

  bool isbal = isBalanced(root);

  cout<<"Is balanced: "<<isbal<<endl;

  cout<<"Height: "<<isBalancedOptimised(root)<<endl;
  return 0;
}