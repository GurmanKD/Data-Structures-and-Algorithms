/*-------------INPUT-OUTPUT METHOD----------------*/
// make recursive tree first

#include<iostream>
#include<string>

using namespace std;

// passing by reference will lead to printing all characters of ip individually
void printSubsets(string ip, string op){
  if(ip.length() == 0){
    cout<<op<<endl;
    return;
  }
  string op1 = op;
  string op2 = op;
  op2.push_back(ip[0]);
  ip.erase(ip.begin()+0);
  printSubsets(ip, op1);
  printSubsets(ip, op2);
  return;
}

int main(){
  string inputStr, outputStr="";

  cout<<"Enter the string"<<endl;
  cin>>inputStr;

  printSubsets(inputStr, outputStr);

  return 0;
}