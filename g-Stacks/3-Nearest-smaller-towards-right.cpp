#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int>nsr(vector<int>ip){
  vector<int>op={};
  stack<int>st={};
  int n = ip.size();
  for (int i = n - 1; i >= 0; i--) {
    // Pop elements from stack while stack's top is less than or equal to ip[i]
        while (!st.empty() && st.top() >= ip[i]) {
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
  vector<int> op = nsr(ip);
  for(int i = 0; i < op.size(); i++){
    cout<< op[i]<<" ";
  }
  return 0;
}