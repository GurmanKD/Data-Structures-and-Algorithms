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

// deleting by index
Node* deleteKth(Node* head, int k){
  if(head==NULL)
    return head;

  if(k ==1 ){
    Node*temp=head;
    head=head->next;
    free(temp);
    return head;
  }

  int count = 0;
  Node*temp=head, *prev=NULL;
  while(temp!=NULL){
    count++;
    if(count==k){
      prev->next=prev->next->next;
      free(temp);
      break;
    }
  prev=temp;
  temp=temp->next;
  }
  return head;
}

// deleting by value
Node* deleteEle(Node* head, int ele){
  if(head==NULL) return head;

  if(head->data == ele ){
    Node*temp=head;
    head=head->next;
    delete temp;
    return head;
  }

  Node*temp=head, *prev=NULL;
  while(temp!=NULL){
    if(temp->data == ele){
      prev->next=prev->next->next;
      delete temp;
      break;
    }
    prev=temp;
    temp=temp->next;
  }
  return head;
}

int main(){
  vector<int> arr = {1, 2, 3, 4};
    Node* ans = convertArr2ll(arr);

    cout<<"before deletion: "<< endl;
    Node* temp = ans;
    for (int i = 0; i < arr.size(); i++) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    ans = deleteKth(ans, 2);
    ans = deleteEle(ans, 1);

    cout<<"after deletion: "<< endl;
    temp = ans;
    for (int i = 0; i < arr.size()-2; i++) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
  return 0;
}