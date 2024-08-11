#include<iostream>
#include<vector>
#include<stack>
#include<algorithm> // for reverse function

using namespace std;

vector<int> findNSLarr(vector<int> v) {
    int n = v.size();
    int pseudoIndex = -1;
    stack<pair<int, int>> st; // {nsl, index}
    vector<int> NSLarr;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top().first >= v[i]) {
            st.pop();
        }
        if (st.empty()) {
            NSLarr.push_back(pseudoIndex);
        } else {
            NSLarr.push_back(st.top().second);
        }
        st.push({v[i], i});
    }
    return NSLarr;
}

vector<int> findNSRarr(vector<int> v) {
    int n = v.size();
    int pseudoIndex = n;
    stack<pair<int, int>> st; // {nsr, index}
    vector<int> NSRarr;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top().first >= v[i]) {
            st.pop();
        }
        if (st.empty()) {
            NSRarr.push_back(pseudoIndex);
        } else {
            NSRarr.push_back(st.top().second);
        }
        st.push({v[i], i});
    }
    reverse(NSRarr.begin(), NSRarr.end());
    return NSRarr;
}

vector<int> findWidthArr(vector<int> nsl, vector<int> nsr) {
    int n = nsl.size();
    vector<int> widthV;

    for (int i = 0; i < n; i++) {
        widthV.push_back(nsr[i] - nsl[i] - 1);
    }
    return widthV;
}

int findMaxArea(vector<int> heights, vector<int> widths) {
    int n = heights.size();
    int maxArea = INT_MIN;

    for (int i = 0; i < n; i++) {
        int currArea = heights[i] * widths[i];
        maxArea = max(maxArea, currArea);
    }
    return maxArea;
}

int main() {
    vector<int> heights = {6, 2, 5, 4, 5, 1, 6};
    vector<int> widths = findWidthArr(findNSLarr(heights), findNSRarr(heights));
    int maxA = findMaxArea(heights, widths);
    cout << "Maximum Area: " << maxA << endl;
    return 0;
}
