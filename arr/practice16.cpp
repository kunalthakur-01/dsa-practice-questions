#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int counter = 0;
        //removing all zeros
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0){
                nums[counter] = nums[i];
                counter++;
            }
        }
        //adding zeros in last
        for(int i = nums.size() - 1; i >= counter; i--){
            nums[i] = 0;
        }


        cout<<"result is => ";
        for(int i = 0; i < nums.size(); i++){
            cout<<nums[i];
            cout<<endl;
        }
    }
};

int main()
{
    vector<int> v = {0,1,0,3,5,0,13};

    Solution s;
    s.moveZeroes(v);

    return 0;

}
