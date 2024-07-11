#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

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
            if (s1[i-1] == s2[j-1])
                t2[i][j] = 1 + t2[i-1][j-1];
            else
                t2[i][j] = max(t2[i-1][j], t2[i][j-1]);
        }
    }
    return t2[m][n];
}

int main() {
    string s1 = "abcdecfdg";
    string s2 = "abc";
    int m = s1.length();
    int n = s2.length();

    (topDownLCS(s1, m, s2, n) == n) ? cout << "present" : cout << "absent";

    return 0;
}
