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

void preInPostTraversal(Node* root){
  stack<pair<Node*, int>>st;
  st.push({root, 1});
  vector<int> pre, in, post;

  if(root == NULL)
    return;

  while(!st.empty()){
    auto it = st.top();
    st.pop();

    if(it.second == 1){
      pre.push_back(it.first->data);
      it.second++;
      st.push(it);

      if(it.first->left)
        st.push({it.first->left, 1});
    }
    else if(it.second == 2){
      in.push_back(it.first->data);
      it.second++;
      st.push(it);

      if(it.first->right)
        st.push({it.first->right, 1});
    }
    else{
      post.push_back(it.first->data);
    }
  }

  cout<<"preorder traversal:"<<endl;
  for(int i=0; i<pre.size(); i++){
    cout<<pre[i]<<" ";
  }
  cout<<endl;

  cout<<"inorder traversal:"<<endl;
  for(int i=0; i<in.size(); i++){
    cout<<in[i]<<" ";
  }
  cout<<endl;

  cout<<"postorder traversal:"<<endl;
  for(int i=0; i<post.size(); i++){
    cout<<post[i]<<" ";
  }
  cout<<endl;

  
}

int main(){
  struct Node*root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);

  root->left->left = new Node(4);

  preInPostTraversal(root);

  return 0;
}