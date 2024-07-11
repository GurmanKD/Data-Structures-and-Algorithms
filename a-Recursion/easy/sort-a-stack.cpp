// g++ -std=c++11 sort-a-stack.cpp -o sort-a-stack && ./sort-a-stack 
// range-based for loop is a C++11 extension [-Wc++11-extensions] for (int num : nums) {

#include <iostream>
using namespace std;
#include <stack>

void insert(stack<int> &st, int temp){
  if(st.size() == 0 || st.top() <= temp){
    st.push(temp);
    return;
  }
  
  int temp2 = st.top();
  st.pop();

  insert(st, temp);
  st.push(temp2);
}

void sort(stack<int> &st){
  if(st.size() == 0)
    return;
  
  int temp = st.top();
  st.pop();

  sort(st);

  insert(st, temp);
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

    sort(st);

    cout << "Sorted stack: ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}