#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int counter = 0;
        int i,j,sign = 0;
        for(i = 0,j = 0; i < nums.size(); i++){
            if(val == nums[i]){
                counter++;
                if(j == 0 && sign == 0){
                   j = i;
                   sign = 1;
                }
            }
            else if(val != nums[i]) {
                if(counter != 0){
                    nums[j] = nums[i];
                    j++;
                    counter--;
                }
                else if(counter == 0 && j != 0){
                    nums[j] = nums[i];
                    j++;
                }
                else {
                j++;
            }
            }
        }

        cout<<"result is:"<<endl;
        for(int i = 0; i < j; i++){
            cout<<nums[i];
            cout<<endl;
        }
    }
};

int main()
{
    vector<int> v = {2,2,4,3,3,3,4,5,6,7,3};

    Solution s;
    s.removeElement(v,2);

    return 0;
}
