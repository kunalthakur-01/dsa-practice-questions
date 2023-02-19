#include <bits/stdc++.h> 
using namespace std;

// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int currSum = 0;
//         for(int i = 0;i < nums.size();i++){
//             currSum += nums[i];
//         }
        
//         int maxSum = currSum;
        
//         int i = 0, j = nums.size();
//         while(i < j) {
//             if((currSum - nums[i]) > (currSum - nums[j])) {
//                 currSum = currSum - nums[i];
//                 i++;
//             } 
//             else if((currSum - nums[i]) < (currSum - nums[j])) {
//                 currSum = currSum - nums[j];
//                 j--;
//             }
//             else {
//                 currSum = currSum - nums[i];
//                 if((currSum - nums[i+1]) > (currSum - nums[j-1])) {
//                     i++;
//                 }
//                 else {
//                     j--;
//                 }
//             }
//             if(currSum > maxSum) {
//                 maxSum = currSum;
//             }
//         }
//         return maxSum;
//     }
// };

class Solution {
    public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int min_sum = 0;
        int ans = INT_MIN;
        for(int n: nums){
            sum += n;
            ans = max(ans, sum - min_sum);
            min_sum = min(min_sum, sum);
        }
        return ans;
    }
};

int main()
{
    Solution s;
    
    vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4};
    
    cout<< s.maxSubArray(arr);

    return 0;
}
