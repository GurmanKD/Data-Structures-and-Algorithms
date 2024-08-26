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

int lengthOfll(Node* head){
  int count = 0;
  Node*temp=head;
  while(temp){
    count++;
    temp=temp->next;
  }
  return count;
}

bool isPresent(Node*head, int val){
  Node*temp=head;
  while(temp){
    if(temp->data == val)
      return true;
    temp = temp->next;
  }
  return false;
}

Node* deleteHead(Node* head) {
    if (head == NULL) {
        return NULL;
    }
    
    Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

Node* deleteTail(Node* head){
  if(head==NULL || head->next==NULL){
    return nullptr;
  }
  Node*temp = head;
  while(temp->next->next!=NULL){
    temp=temp->next;
  }
  temp->next=nullptr;
  free(temp->next);
  return head;

}

int main() {
    vector<int> arr = {1, 2, 3, 4};
    Node* ans = convertArr2ll(arr);

    Node* temp = ans;
    for (int i = 0; i < arr.size(); i++) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    int count = lengthOfll(ans);
    cout << "count is: " << count << endl;

    cout << "Is 4 present: " << (isPresent(ans, 4) ? "Yes" : "No") << endl;


    cout << "after deletion of head: " << endl;
    ans = deleteHead(ans);  

    temp = ans;
    for (int i = 0; i < arr.size() - 1; i++) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    cout << "after deletion of tail: " << endl;
    ans = deleteTail(ans);  

    temp = ans;
    for (int i = 0; i < arr.size() - 2; i++) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}