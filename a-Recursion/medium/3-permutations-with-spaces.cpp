/*-------------INPUT-OUTPUT METHOD----------------*/
// make recursive tree first

/*
abc =>  abc
        a_bc
        ab_c
        a_b_c

        !!! we don't want _abc / _a_bc / _ab_c / _abc_ / _a_b_c_ !!!

CHOICES:
        1. include the letter with space (_a)
        2. include the letter w/o space (a)

                        ( "", "abc")

                        ("a",  "bc") (no choice, include w/o space)

                ("a_b",  "c")     ("ab",  "") 

("a_b_c",  "")   ("a_bc",  "")    ("ab_c",  "")   ("abc",  "")
*/

#include<iostream>

using namespace std;

void generatePermutations(string op, string ip){
        if(ip.length() == 0){
                cout<<op<<endl;
                return;
        }
        // with space
        string op1 = op;
        op1.push_back(' ');
        op1.push_back(ip[0]);

        // without space
        string op2 = op;
        op2.push_back(ip[0]);

        // make input smaller
        ip.erase(ip.begin()+0);

        // recursive calls
        generatePermutations(op1, ip);
        generatePermutations(op2, ip);
        return;
}

int main(){
        string inputStr;
        cout<<"Enter the string: ";
        cin>>inputStr;

        string outputStr = "";

        outputStr.push_back(inputStr[0]);
        inputStr.erase(inputStr.begin() + 0);

        generatePermutations(outputStr, inputStr);

        return 0;
}



