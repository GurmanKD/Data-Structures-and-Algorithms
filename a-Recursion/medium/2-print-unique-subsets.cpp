/*
other headings for the same question: 

1. Print the power set (all subsets of a set)
{a, b} => { , a, b, ab}

2. Print all subsequences
  in subsequence, the order matters
  you can take multiple parts of a string but the order must be maintained

all substrings are subsequences
all subsequences are subsets

just the thing is, in subsets you have a freedom to print the characters in any order
*/

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

void printSubsets(string ip, string op, unordered_set<string>& subsets) {
    if (ip.length() == 0) {
        subsets.insert(op);
        return;
    }

    string op1 = op;
    string op2 = op;
    op2.push_back(ip[0]);
    ip.erase(ip.begin() + 0);
    printSubsets(ip, op1, subsets);
    printSubsets(ip, op2, subsets);
    return;
}

int main() {
    string inputStr, outputStr = "";
    unordered_set<string> subsets;

    cout << "Enter the string: ";
    cin >> inputStr;

    printSubsets(inputStr, outputStr, subsets);

    cout << "Unique subsets are:" << endl;
    for (const string& subset : subsets) {
        cout << subset << endl;
    }

    return 0;
}
