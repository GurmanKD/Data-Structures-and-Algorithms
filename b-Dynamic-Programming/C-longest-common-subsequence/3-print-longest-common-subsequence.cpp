// #include <iostream>
// #include <string>
// #include <cstring>
// using namespace std;

// string recLCS(string s1, int m, string s2, int n, int& maxLen, string currentStr) {
//     if (m == 0 || n == 0) {
//         if (currentStr.length() > maxLen) {
//             maxLen = currentStr.length();
//             return currentStr;
//         }
//         return "";
//     }

//     if (s1[m - 1] == s2[n - 1]) {
//         currentStr = s1[m - 1] + currentStr;
//         return recLCS(s1, m - 1, s2, n - 1, maxLen, currentStr);
//     } else {
//         string str1 = recLCS(s1, m - 1, s2, n, maxLen, "");
//         string str2 = recLCS(s1, m, s2, n - 1, maxLen, "");
//         return (str1.length() > str2.length()) ? str1 : str2;
//     }
// }

// int main() {
//     string s1 = "abcdefg";
//     int m = s1.length();
//     string s2 = "aabbccdd";
//     int n = s2.length();
//     int maxLen = 0;
//     string lcs = recLCS(s1, m, s2, n, maxLen, "");
//     cout << "Longest common substring: " << lcs << endl;
//     return 0;
// }

// print the length of longest common subsequence
// subsequence need not be continuous

#include<iostream>
#include<string>
#include<algorithm>
#include<cstring> // For memset

using namespace std;

// Recursive LCS
int recLCS(string s1, int m, string s2, int n) {
    if (m == 0 || n == 0)
        return 0;

    if (s1[m - 1] == s2[n - 1])
        return 1 + recLCS(s1, m - 1, s2, n - 1);
    else
        return max(recLCS(s1, m, s2, n - 1), recLCS(s1, m - 1, s2, n));
}

// Memoization LCS
int static t1[1001][1001];

int memoLCS(string s1, int m, string s2, int n) {
    if (m == 0 || n == 0)
        return 0;

    if (t1[m][n] != -1)
        return t1[m][n];

    if (s1[m - 1] == s2[n - 1])
        return t1[m][n] = 1 + memoLCS(s1, m - 1, s2, n - 1);
    else
        return t1[m][n] = max(memoLCS(s1, m, s2, n - 1), memoLCS(s1, m - 1, s2, n));
}

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
    string s1 = "abcdefg";
    int m = 7;
    string s2 = "aabbccdd";
    int n = 8;

    cout << recLCS(s1, m, s2, n) << endl;

    memset(t1, -1, sizeof(t1));
    cout << memoLCS(s1, m, s2, n) << endl;

    cout << topDownLCS(s1, m, s2, n) << endl;

    // Reconstructing LCS string
    string lcs = "";

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            lcs.push_back(s1[i - 1]);
            i--;
            j--;
        } else {
            if (t2[i][j - 1] > t2[i - 1][j])
                j--;
            else
                i--;
        }
    }

    reverse(lcs.begin(), lcs.end());
    cout << lcs << endl;

    return 0;
}
