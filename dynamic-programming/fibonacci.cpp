#include<iostream>
#include<vector>

using namespace std;

// DP top down approach****************************************************************************************************************
// int fibonacci(int n, vector<int> &dp){
//     if(n <= 1){
//         return n;
//     }
//     if(dp[n] != -1) return dp[n];
    
//     dp[n] =  fibonacci(n-1, dp) + fibonacci(n-2, dp);
//     return dp[n];
// }

// DP bottom up approach****************************************************************************************************************
int fibonacci(int n){
    
    vector<int> dp(n+1);
    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int main(){
    int n = 4;
    vector<int> dp(n+1, -1);
    cout << fibonacci(n);
    return 0;
}
