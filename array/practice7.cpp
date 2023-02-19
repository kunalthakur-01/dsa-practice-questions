#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i += 3){
            if(target == nums[i]){
                return i;
            }
            else if(target == nums[i-1]){
                return i - 1;
            }
            else if(target == nums[i+1]){
                return i + 1;
            }
            else{
                if(target == nums[i+2]){
                    return i + 2;
                }
                else if(target < nums[i-1] && i-1 != -1){
                    return i-1;
                }
                else if(target < nums[i+1] ){
                    return i+1;
                }
                else if(target > nums[i] && i == nums.size()-1){
                    return i+1;
                }
            }
        }

        return 0;
    }
};

int main()
{
    vector<int> v = {1,3,5,6};

    Solution s;
    int result;
    result = s.searchInsert(v,0);
    cout<<result;

    return 0;
}

