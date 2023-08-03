#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>

using namespace std;

// Recursive solution********************************************************************************************************************
// int frogJump(int i, vector<int> heights) {
//     if(i == 0) return 0;

//     int left = frogJump(i-1, heights) + abs(heights[i] - heights[i-1]);
//     int right = INT_MAX;
//     if(i > 1) int right = frogJump(i-2, heights) + abs(heights[i] - heights[i-2]);

//     return min(left, right);
// }

// int main() {
//     vector<int> heights = {20,30,40,10};
//     frogJump(heights.size()-1, heights);
// }


// Top down solution*********************************************************************************************************************
// int frogJump(int i, vector<int> heights, vector<int> &dp) {
//     if(i == 0) return 0;

//     if(dp[i] != -1) return dp[i];

//     int left = frogJump(i-1, heights, dp) + abs(heights[i] - heights[i-1]);
//     int right = INT_MAX;
//     if(i > 1) int right = frogJump(i-2, heights, dp) + abs(heights[i] - heights[i-2]);

//     return dp[i] = min(left, right);
// }

// int main() {
//     vector<int> heights = {20,30,40,10};
//     int n = heights.size();
//     vector<int> dp(n+1, -1);
//     frogJump(n-1, heights, dp);
// }

// Bottom up approach*******************************************************************************************************************
int frogJump(int n, vector<int> heights) {
    vector<int> dp;

    dp[0] = 0;

    for(int i = 0; i < n; i++) {
        int firstStep = dp[i - 1] + abs(heights[i] - heights[i-1]);
        int secondStep =  INT_MAX;
        if(i > 1) secondStep = dp[i - 2] + abs(heights[i] - heights[i-2]);

        dp[i] = min(firstStep, secondStep);
    }

    return dp[n - 1];
}

int main() {
    vector<int> heights = {20,30,40,10};
    int n = heights.size();
    frogJump(n, heights);
}

