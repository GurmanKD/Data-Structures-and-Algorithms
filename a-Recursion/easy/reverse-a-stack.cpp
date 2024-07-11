#include<iostream>
using namespace std;
#include<stack>

void insert(stack<int>& st, int temp){

  if(st.size() == 0){
    st.push(temp);
    return;
  }

  int temp2 = st.top();
  st.pop();
  insert(st, temp);
  st.push(temp2);
  return;
}

void reverse(stack<int>&st){
  if(st.size() == 0 || st.size() == 1)
    return;

  int temp = st.top();
  st.pop();
  reverse(st);
  insert(st, temp);
  return;
}

int main() {
    vector<int> nums = {4, 3, 2, 1, 5, 7, 6};
    stack<int> st;

    for (int num : nums) {
        st.push(num);
    }

    cout << "Original stack: ";

    stack<int> tempSt = st; // copy to avoid modifying the original stack
    while (!tempSt.empty()) {
        cout << tempSt.top() << " ";
        tempSt.pop();
    }
    cout << endl;

    reverse(st);

    cout << "Reversed stack: ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    cout << endl;

    return 0;
}

