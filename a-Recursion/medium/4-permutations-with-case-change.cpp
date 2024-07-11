/*
It is provided that the input is in smallcase.

ab => ab
      aB
      Ab
      AB
 */

#include<iostream>
using namespace std;

void generatePermutations(string op, string ip){
  if(ip.length() == 0){
    cout<<op<<endl;
    return;
  }

  // with lowercase
  string op1 = op;
  op1.push_back(ip[0]);

  // with uppercase
  string op2 = op;
  op2.push_back(toupper(ip[0]));

  // make the input smaller
  ip.erase(ip.begin()+0);

  // recursive calls
  generatePermutations(op1, ip);
  generatePermutations(op2, ip);

  return;
}

int main(){
  string inputStr;
  cout<<"Enter the string:";
  cin>>inputStr;

  string outputStr = "";

  generatePermutations(outputStr, inputStr);

  return 0;
}