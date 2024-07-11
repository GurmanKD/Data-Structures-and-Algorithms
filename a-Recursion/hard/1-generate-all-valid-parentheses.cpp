#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> generate(string op, int open, int close, vector<string>& ans) {
    if (open == 0 && close == 0) {
        ans.push_back(op);
        return ans;
    }

    if (open != 0) {
        // ( 
        string op1 = op;
        op1.push_back('(');

        // recursive call
        generate(op1, open - 1, close, ans);
    }

    if (open < close) {
        // )
        string op2 = op;
        op2.push_back(')');

        // recursive call
        generate(op2, open, close - 1, ans);
    }

    return ans;
}

int main() {
    int n;
    cout << "Enter the no. of pairs of parentheses: ";
    cin >> n;

    string op = "";

    vector<string> ans;

    generate(op, n, n, ans);

    for (const string& s : ans) {
        cout << s << endl;
    }

    return 0;
}
