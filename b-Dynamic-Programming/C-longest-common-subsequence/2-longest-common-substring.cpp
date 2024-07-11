// return thr length of longest common substring

// substring needs to be continuous

#include<iostream>
#include<string>
#include<cstring>

using namespace std;

int recLCS(string s1, int m, string s2, int n, int &maxLen) {
    if (m == 0 || n == 0)
        return 0;

    int res = 0;
    if (s1[m - 1] == s2[n - 1]) {
        res = 1 + recLCS(s1, m - 1, s2, n - 1, maxLen);
        maxLen = max(maxLen, res);
    } else {
        recLCS(s1, m, s2, n - 1, maxLen);
        recLCS(s1, m - 1, s2, n, maxLen);
    }
    return res;
}

int static t1[1001][1001];

int memoLCS(string s1, int m, string s2, int n, int &maxLen) {
    if (m == 0 || n == 0) 
        return 0;

    if (t1[m][n] != -1)
        return t1[m][n];

    int res = 0;
    if (s1[m - 1] == s2[n - 1]) {
        res = 1 + memoLCS(s1, m - 1, s2, n - 1, maxLen);
        maxLen = max(maxLen, res);
    }
    t1[m][n] = res;
    memoLCS(s1, m, s2, n - 1, maxLen);
    memoLCS(s1, m - 1, s2, n, maxLen);

    return res;
}

int static t2[1001][1001];

int topDownLCS(string s1, int m, string s2, int n) {
    int maxLen = 0;

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                t2[i][j] = 0;
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                t2[i][j] = 1 + t2[i - 1][j - 1];
                maxLen = max(maxLen, t2[i][j]);
            } else {
                t2[i][j] = 0;
            }
        }
    }

    return maxLen;
}

int main(){
  string s1 = "abcdefg";
  int m = 7;
  string s2 = "abbcdede";
  int n = 8;

  int maxLenRec = 0;
  recLCS(s1, m, s2, n, maxLenRec);
  cout << maxLenRec << " (using recursion)" << endl;

  memset(t1, -1, sizeof(t1));
  int maxLenMemo = 0;
  memoLCS(s1, m, s2, n, maxLenMemo);
  cout << maxLenMemo << " (using memoization)" << endl;

  cout << topDownLCS(s1, m, s2, n) << " (using top-down)" << endl;

  return 0;
}