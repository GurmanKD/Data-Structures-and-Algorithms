#include<iostream>
#include<new>
#include<stack>
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

void iterativePreorder(Node* root){
  if(root == NULL)
    return;
  
  stack<Node*>s;
  s.push(root); 

  while(!s.empty()){
    Node* temp = s.top();
    s.pop();
    cout<<temp->data;
    if(temp->right)
      s.push(temp->right);
    if(temp->left)
      s.push(temp->left);
    // we pushed right first because LIFO
  }
}

vector<int> iterativeInorder(Node* root){
  vector<int> inorder;
  if(root == NULL)
    return inorder;
  
  stack<Node*>s;

  Node*temp = root;

  while(true){
    if(temp!=NULL){
      s.push(temp);
      temp = temp->left;
    }else{
      if(s.empty())
        break;
      
      temp = s.top();
      s.pop();

      inorder.push_back(temp->data);
      temp = temp->right;
    }
  } 
  return inorder;
}

vector<int> iterativePostorder(Node* root){
  vector<int>postorder;
  stack<Node*> s1, s2;
  s1.push(root);
  while(!s1.empty()){
    Node* temp = s1.top();
    s1.pop();
    s2.push(temp);
    if(temp->left)
      s1.push(temp->left);
    if(temp->right)
      s1.push(temp->right);
  }
  while(!s2.empty()){
    postorder.push_back(s2.top()->data);
    s2.pop();
  }
  return postorder;
}
int main(){
  struct Node*root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);

  root->left->left = new Node(4);

  cout<<"preorder traversal:"<<endl;
  iterativePreorder(root);
  cout<<endl;

  cout<<"inorder traversal:"<<endl;
  vector<int>inorder = iterativeInorder(root);
  for(int i=0; i<inorder.size(); i++){
    cout<<inorder[i]<<" ";
  }
  cout<<endl;

  cout<<"postorder traversal:"<<endl;
  vector<int>postorder = iterativePostorder(root);
  for(int i=0; i<postorder.size(); i++){
    cout<<postorder[i]<<" ";
  }
  cout<<endl;


  return 0;
}