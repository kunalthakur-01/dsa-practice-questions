#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
public:
    int missingNumberAndDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != i){
                // cout<<"missing-->"<<i+1<<endl;
                return i;
            }
            if(i == nums.size() - 1){
                return i+1;
            }
        }
        return -1;
    }
};

int main()
{
    Solution s;
    vector<int> v ={1,3,4,2,6,7,8,7,9};
    int res = s.missingNumberAndDuplicate(v);

    return res;
}
