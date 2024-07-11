#include<iostream>
#include<vector>
using namespace std;

// Recursive approach (without memoization)
int recCountWays(vector<int> coins, int sum, int n) {
    if (sum == 0) return 1;
    if (n == 0) return 0;
    
    if (coins[n-1] <= sum) {
        return recCountWays(coins, sum - coins[n-1], n) + recCountWays(coins, sum, n-1);
    } else {
        return recCountWays(coins, sum, n-1);
    }
}

// Memoization approach
int static t1[7][11];

int memoCountWays(vector<int> coins, int sum, int n) {
    if (sum == 0) return 1;
    if (n == 0) return 0;
    
    if (t1[n][sum] != -1) {
        return t1[n][sum];
    }

    if (coins[n-1] <= sum) {
        return t1[n][sum] = memoCountWays(coins, sum - coins[n-1], n) + memoCountWays(coins, sum, n-1);
    } else {
        return t1[n][sum] = memoCountWays(coins, sum, n-1);
    }
}

// Top-down approach (Tabulation)
int topDownCountWays(vector<int> coins, int sum, int n) {
    vector<vector<int>> t2(n + 1, vector<int>(sum + 1, 0));

    // Initialization
    for (int i = 0; i <= n; i++) {
        t2[i][0] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (coins[i-1] <= j) {
                t2[i][j] = t2[i][j - coins[i-1]] + t2[i-1][j];
            } else {
                t2[i][j] = t2[i-1][j];
            }
        }
    }

    return t2[n][sum];
}

int main() {
    vector<int> coins = {2, 3, 5, 6, 8, 10};
    int sum = 10;
    int n = coins.size();

    // Recursive approach
    // cout << recCountWays(coins, sum, n) << " ways to make the sum using given coins (recursive)." << endl;

    // Memoization approach
    memset(t1, -1, sizeof(t1));
    // cout << memoCountWays(coins, sum, n) << " ways to make the sum using given coins (memoization)." << endl;

    // Top-down approach (Tabulation)
    cout << topDownCountWays(coins, sum, n) << " ways to make the sum using given coins (top-down)." << endl;

    return 0;
}
