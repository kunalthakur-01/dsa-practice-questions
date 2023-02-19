#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int store;
        for(int i = 0; i < k; i++){
            for(int j = nums.size() - 1; j >= 0; j--){
                if(j == nums.size() - 1){
                    store = nums[j];
                }
                else{
                    nums[j+1] = nums[j];
                }
            }
            nums[0] = store;
        }
        cout<<"after right shift => "<<endl;
        for(int i = 0; i < nums.size(); i++){
            cout<<nums[i];
        }
    }
};

int main()
{
    vector<int> v = {-1,-100,3,99};

    Solution s;
    s.rotate(v, 2);

    return 0;

}

