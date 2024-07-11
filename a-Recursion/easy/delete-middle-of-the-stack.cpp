#include<iostream>
using namespace std;
#include<stack>

void deleteMid(stack<int> &st, int k){
  if (st.empty() || k == 0) {
        return;
    }

    int temp = st.top();
    st.pop();

    deleteMid(st, k - 1);

    // Only push the element back if it's not the middle one
    if (k != 1) {
        st.push(temp);
    }
}

int main(){
  vector<int> nums = {4, 3, 2, 1, 5, 7, 6};
    stack<int> st;

    for (int num : nums) {
        st.push(num);
    }

    cout << "Original stack: ";

    stack<int> tempSt = st; 

    while (!tempSt.empty()) {
        cout << tempSt.top() << " ";
        tempSt.pop();
    }
    cout << endl;

    int mid = st.size()/2 + 1;

    deleteMid(st, mid);

    cout << "Stack after deleting middle element: ";

    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

  return 0;
}