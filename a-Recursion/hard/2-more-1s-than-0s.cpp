/*
Print n-bit binary numbers having more 1's greater than or equal to number of 0's for any prefix.

eg: 110110 3>=3
    11010  3>2
    1101   3>1
    110    2>1
    11     2>0
    1      1>0
*/

#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<string> generate(int zeros, int ones, int n, string op, vector<string>& ans){
  if(n == 0){
    ans.push_back(op);
    return ans;
  }
  string op1 = op;
  op1.push_back('1');
  generate(zeros, ones+1, n-1, op1, ans);

  if(zeros<ones){
    string op2 = op;
    op2.push_back('0');
    generate(zeros+1, ones, n-1, op2, ans);
  }
  return ans;
}

int main(){
  int n;
  cout<<"Enter n:";
  cin>>n;

  int ones = 0, zeros = 0;

  string outputStr = "";

  vector<string> ans;

  generate(zeros, ones, n, outputStr, ans);

  for(string s : ans){
    cout<<s<<endl;
  }
  return 0;
}