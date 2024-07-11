#include<iostream>
#include<vector>
using namespace std;

// Recursive approach (without memoization)
int recCountWays(vector<int> coins, int sum, int n) {
    if (sum == 0) return 0;
    if (n == 0) return INT_MAX-1;

    if(n == 1){
      if(sum % coins[0] == 0) 
        return sum/coins[0];
      else  
        return INT_MAX-1;
    }
    
    if (coins[n-1] <= sum) {
        return min(recCountWays(coins, sum - coins[n-1], n) + 1, recCountWays(coins, sum, n-1));
    } else {
        return recCountWays(coins, sum, n-1);
    }
}

// Memoization approach
int static t1[7][11];

int memoCountWays(vector<int> coins, int sum, int n) {
    if (sum == 0) return 0;
    if (n == 0) return INT_MAX-1;

    if(n == 1){
      if(sum % coins[0] == 0) 
        return sum/coins[0];
      else  
        return INT_MAX-1;
    }
    
    if (t1[n][sum] != -1) {
        return t1[n][sum];
    }

    if (coins[n-1] <= sum) {
        return t1[n][sum] = min(memoCountWays(coins, sum - coins[n-1], n) + 1,  memoCountWays(coins, sum, n-1));
    } else {
        return t1[n][sum] = memoCountWays(coins, sum, n-1);
    }
}


// !!!!!!!!!!!!!!!!!revisit below code
// Top-down approach (Tabulation)
int topDownCountWays(vector<int> coins, int sum, int n) {
    vector<vector<int>> t2(n + 1, vector<int>(sum + 1));

    // Initialization
    for (int j = 0; j <= sum; j++) {
        t2[j][0] = INT_MAX-1;
    }

    for (int i = 1; i <= n; i++) {
        t2[0][i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (i == 1) {
              if(j % coins[0] == 0) 
                t2[i][j] =  j/coins[0];
              else  
                t2[i][j] =  INT_MAX-1;
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (coins[i-1] <= j) {
                t2[i][j] = min(t2[i][j - coins[i-1]] + 1, t2[i-1][j]);
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
    cout << recCountWays(coins, sum, n) << " ways to make the sum using given coins (recursive)." << endl;

    // Memoization approach
    memset(t1, -1, sizeof(t1));
    cout << memoCountWays(coins, sum, n) << " ways to make the sum using given coins (memoization)." << endl;

    // Top-down approach (Tabulation)
    cout << topDownCountWays(coins, sum, n) << " ways to make the sum using given coins (top-down)." << endl;

    return 0;
}
