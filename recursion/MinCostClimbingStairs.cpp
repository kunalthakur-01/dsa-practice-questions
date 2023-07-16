#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int solve(vector<int> cost, int n) {
        if(n == 0 || n == 1) return cost[n];

        int ans = cost[n] + min(solve(cost, n-1), solve(cost, n-2));
        return ans;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        // int ans = min(solve(cost, n-1), solve(cost, n-2));
        // or
        // improved way
        cost.push_back(0);
        int ans = solve(cost, n);
        return ans;
    }
};