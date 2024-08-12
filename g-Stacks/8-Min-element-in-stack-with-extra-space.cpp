#include<iostream>
#include<stack>

using namespace std;

stack<int> s, ss;
// ss is supporting stack

void pushInMin(int ele){
  s.push(ele);
  if(ss.size()==0 || ss.top()>=ele){
    // if an element gets pushed twice and deleted once, one should remain, hence >=
    ss.push(ele);
    return;
  }
}

int popFromMin(){
  if(s.size() == 0)
    return -1;
  int ans = s.top();
  s.pop();
  if(ss.top()==ans){
    ss.pop();
  }
  return ans;
}

int getMin(){
  if(ss.size()==0)
    return -1;
  return ss.top();
}

int main(){
  pushInMin(1);
  pushInMin(2);
  pushInMin(3);
  cout<<getMin();

  return 0;
}