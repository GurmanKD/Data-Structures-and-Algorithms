#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

// Top-down DP LCS
int static t2[1001][1001];

int topDownLCS(string s1, int m, string s2, int n) {
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                t2[i][j] = 0;
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1])
                t2[i][j] = 1 + t2[i - 1][j - 1];
            else
                t2[i][j] = max(t2[i - 1][j], t2[i][j - 1]);
        }
    }

    return t2[m][n];
}

int main() {
    string s1 = "abc";
    int m = 3;
    string s2 = "cdef";
    int n = 4;

    cout << topDownLCS(s1, m, s2, n) << endl;

    // Reconstructing LCS string
    string scs = "";

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            scs.push_back(s1[i - 1]);
            i--;
            j--;
        } else {
            if (t2[i][j - 1] > t2[i - 1][j]){
              scs.push_back(s2[j-1]);
              j--;
            }
            else{
              scs.push_back(s1[i-1]);
              i--;
            }
        }
    }
    while(i > 0){
      scs.push_back(s1[i-1]);
      i--;
    }
    while(j > 0){
      scs.push_back(s2[j-1]);
      j--;
    }

    reverse(scs.begin(), scs.end());
    cout << scs << endl;

    return 0;
}