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

Node* convertArr2ll(vector<int>arr){
  Node* head = new Node(arr[0]);
  Node* mover = head;
  for(int i=1; i<arr.size(); i++){
    Node* temp = new Node(arr[i]);
    mover->next=temp;
    mover=temp;
  }
  return head;
}

Node* insertAtHead(Node*head, int ele){
    Node* temp = new Node(ele, head);
    return temp;
}

int main(){
  vector<int> arr = {1, 2, 3, 4};
    Node* ans = convertArr2ll(arr);

    cout<<"before insertion at head: "<< endl;
    Node* temp = ans;
    for (int i = 0; i < arr.size(); i++) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    ans = insertAtHead(ans, 100);

    cout<<"after insertion at head: "<< endl;
    temp = ans;
    for (int i = 0; i < arr.size()+1; i++) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
  return 0;
}