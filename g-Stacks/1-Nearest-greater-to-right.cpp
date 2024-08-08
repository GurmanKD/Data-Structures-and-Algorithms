#include<iostream>
#include<vector>
#include<stack>
using namespace std;

// we need to check nearest greater element towards right
// so we need to check from the immediate right of the element and then move towards the end of the arrar
// so to compare the immediate next element first, it should be on the top of the stack (as LIFO)
// so, we will push the last element of the array first

// stack stores the necessary right array

// Eg. If tyhe right array is 3, 2, 4
// as 3>2 ans 3 appears before 2, 2 will never be the nearest greater, so we will pop it safely beforehand

vector<int>ngr(vector<int>ip){
  vector<int>op={};
  stack<int>st={};
  int n = ip.size();
  for (int i = n - 1; i >= 0; i--) {
    // Pop elements from stack while stack's top is less than or equal to ip[i]
        while (!st.empty() && st.top() <= ip[i]) {
            st.pop();
        }

        // If stack is empty, no greater element exists
        if (st.empty()) {
            op.push_back(-1);
        } else {
            op.push_back(st.top());
        }

        // Push current element to stack
        st.push(ip[i]);
    }

  reverse(op.begin(), op.end());
  return op;
}

int main(){
  vector<int> ip = {1, 3, 2, 4};
  vector<int> op = ngr(ip);
  for(int i = 0; i < op.size(); i++){
    cout<< op[i]<<" ";
  }
  return 0;
}