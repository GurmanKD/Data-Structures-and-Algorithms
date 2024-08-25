#include<iostream>
#include<new>
#include<vector>
using namespace std;

struct Node{
  public:
    int data;
    Node* next;

    Node(int data1, Node*next1){
      data = data1;
      next=next1;
    }

    Node(int data1){
      data = data1;
      next=NULL;
    }
};

int main(){
  vector<int>arr={1,2,3,4};
  Node*y = new Node(arr[0]);
  cout<<y->data;
  return 0;
}