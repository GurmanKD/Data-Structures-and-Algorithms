/*
The characters of the input can be in both,  alphabet in uppercase / lowercase or digits.

a1B2 => a1b2
        A1b2
        a1B2
        A1B2

CHOICES:  if alphabet=> 1. include with tolower()
                        2. include with toupper()
          if digit =>   must be included (no chioice)
*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<string> generatePermutations(string op, string ip, vector<string>& permutations){
  if(ip.length() == 0){
    permutations.push_back(op);
    return permutations;
  }

  if(isalpha(ip[0])){

    // add with lowercase
    string op1 = op;
    op1.push_back(tolower(ip[0]));

    // add with uppercase
    string op2 = op;
    op2.push_back(toupper(ip[0]));

    // make input smaller
    ip.erase(ip.begin()+0);

    // recursive calls
    generatePermutations(op1, ip, permutations);
    generatePermutations(op2, ip, permutations);

  }else if(isdigit(ip[0])){

    // simply add the digit to the output
    string op3 = op;
    op3.push_back(ip[0]);

    // make input smaller
    ip.erase(ip.begin()+0);

    //recursive call
    generatePermutations(op3, ip, permutations);
  }
  return permutations;
}

int main(){
  string inputStr;
  cout<<"Enter the string:";
  cin>>inputStr;

  string outputStr = "";

  vector<string> permutations;

  generatePermutations(outputStr, inputStr, permutations);

  for(string s: permutations){
    cout<<s<<endl;
  }
  return 0;
}