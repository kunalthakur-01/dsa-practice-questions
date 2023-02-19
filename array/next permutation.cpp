#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> nextPermutation(vector<int>& nums) {
        for(int i = nums.size() - 1; i > 0; i--){
            if(nums[i] > nums[i-1]){
                int j = nums.size() - 1;
                while(j >= i)
                {
                    if(nums[j] > nums[i-1]){
                        swap(nums[i-1], nums[j]);
                        sort(nums.begin() + i, nums.end());
                        return nums;
                    }
                    j--;
                }
            }
            if((i-1) == 0){
                sort(nums.begin(), nums.end());
                return nums;
            }
        }
    }
};

int main()
{
    Solution s;
    vector<int> v = {3,2,1};
    vector<int> res = s.nextPermutation(v);

    for(int i = 0; i < res.size(); i++){
        cout<<res[i]<<" ";
    }
    return 0;
}
