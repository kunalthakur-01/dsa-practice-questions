#include<iostream>
#include<vector>
using namespace std;

// Simple Recursion
// class Solution {
// public:
//     int solve(vector<int> cost, int n) {
//         if(n == 0 || n == 1) return cost[n];

//         int ans = cost[n] + min(solve(cost, n-1), solve(cost, n-2));
//         return ans;
//     }
//     int minCostClimbingStairs(vector<int>& cost) {
//         int n = cost.size();

//         // int ans = min(solve(cost, n-1), solve(cost, n-2));
//         // or
//         // improved way
//         cost.push_back(0);
//         int ans = solve(cost, n);
//         return ans;
//     }
// };


// Top down approach
// class Solution {
// public:
//     int solve(vector<int> cost, int n, vector<int> &dp) {
//         if(n == 0 || n == 1) return cost[n];

//         if(dp[n] != -1) return dp[n];

//         dp[n] = cost[n] + min(solve(cost, n-1, dp), solve(cost, n-2, dp));
//         return dp[n];
//     }
//     int minCostClimbingStairs(vector<int>& cost) {
//         int n = cost.size();

//         // int ans = min(solve(cost, n-1), solve(cost, n-2));
//         // or
//         // improved way
//         cost.push_back(0);
//         vector<int> dp(n+1, -1);

//         int ans = solve(cost, n, dp);
//         return ans;
//     }
// };


// Bottom up approach
// class Solution {
// public:
//     int minCostClimbingStairs(vector<int>& cost) {
//         int n = cost.size();
//         vector<int> dp(n+1, -1);
//         dp[0] = cost[0];
//         dp[1] = cost[1];

//         for(int i = 2; i < n; i++) {
//             dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
//         }
//         return min(dp[n-1], dp[n-2]);
//     }
// };



// Bottom up approach
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int prev1 = cost[1], prev2 = cost[0];

        for(int i = 2; i < n; i++) {
            int curr = cost[i] + min(prev1, prev2);
            prev2 = prev1;
            prev1 = curr;
        }
        return min(prev1, prev2);
    }
};