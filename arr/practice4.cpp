#include<iostream>
#include<vector>
using namespace std;

/*class Solution {
public:
     void twoSum(vector<int> nums, int target) {
        for(int i = 0; i < nums.size(); i++){
           for(int j = i + 1; j < nums.size(); j++) {
               if(nums[i] + nums[j] == target){
                   nums.clear();
                   nums.push_back(i);
                   nums.push_back(j);
                   display(nums);
               }
           }
        }
    }

    void display(vector<int> n)
    {
        for(int j = 0; j < n.size(); j++)
        {
            cout<<n[j];
            cout<<endl;
        }
    }
};

int main(){
    vector<int> result = {2,7,11,15};
    Solution s;
    s.twoSum(result, 13);

    return 0;
}*/


/*Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.



Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation:
nums[0] + nums[1] + nums[1] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.*/


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> vec;
        vector<int> v1;
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = 0; j < nums.size(); j++)
            {
                for(int k = 0; k < nums.size(); k++)
                {
                    if(i != j && j != k && i != k)
                    {
                        if(nums[i] + nums[j] + nums[k] == 0)
                        {
                            v1.push_back(nums[i]);
                            v1.push_back(nums[j]);
                            v1.push_back(nums[k]);
                            break;
                        }
                    }
                    //if(nums[i] == vec[i][])
                    vec.push_back(v1);
                    v1.clear();
                }
            }
        }
        cout<<vec.size();
        for(int i = 0; i < vec.size(); i++)
        {
            for(int j = 0; j < vec[i].size(); j++)
            {
                cout<<vec[i][j]<<" ";

            }
            cout<<endl;
        }

        return vec;
    }
};

int main()
{
    Solution s;
    vector<int> result = {-1,0,1,2,-1,-4};
    s.threeSum(result);

    return 0;
}






/*int main()
{
    vector<int> vect = {0,1,2,3,4,5};

    cout<<"enter the value=";
    for(int i = 0; i < vect.size(); i++)
    {
        cout<<vect[i];
        cout<<endl;
    }
}*/
