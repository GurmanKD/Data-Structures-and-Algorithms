/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
Input: arr[]   = {2, 0, 2}
Output: 2
*/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> calcLeftMax(vector<int> v) {
    int n = v.size();
    vector<int> leftMax(n);
    
    leftMax[0] = v[0];  // The first bar's left max is itself
    for (int i = 1; i < n; i++) {
        leftMax[i] = max(leftMax[i - 1], v[i]);
    }
    return leftMax;
}

vector<int> calcRightMax(vector<int> v) {
    int n = v.size();
    vector<int> rightMax(n);
    
    rightMax[n - 1] = v[n - 1];  // The last bar's right max is itself
    for (int i = n - 2; i >= 0; i--) {
        rightMax[i] = max(rightMax[i + 1], v[i]);
    }
    return rightMax;
}

int calcTrappedWater(vector<int> heights) {
    int n = heights.size();
    
    if (n == 0) return 0;  
    
    vector<int> leftMax = calcLeftMax(heights);
    vector<int> rightMax = calcRightMax(heights);
    
    int trappedWater = 0;
    for (int i = 0; i < n; i++) {
        // Water trapped at bar i is the minimum of the max heights on both sides minus the height of the current bar
        trappedWater += min(leftMax[i], rightMax[i]) - heights[i];
    }
    
    return trappedWater;
}

int main() {
    vector<int> heights = {3, 0, 0, 2, 0, 4};
    int ans = calcTrappedWater(heights);
    cout << "Rainwater trapped: " << ans << endl;
    return 0;
}
