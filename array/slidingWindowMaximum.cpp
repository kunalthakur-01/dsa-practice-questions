#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    /*vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        int max;
        vector<int> temp;
        for(int i = 0; i <= nums.size() - k; i++)
        {
            max = nums[i];
            for (int j = i; j < i + k; j++)
            {
                if(nums[j] > max){
                    max = nums[j];
                }
            }
            temp.push_back(max);

        }
        cout<<"result is -->"<<endl;
        for(int i = 0; i < temp.size(); i++)
        {
            cout<<temp[i]<<" ";
        }

        return temp;
    }*/


    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        int max = nums[0];
        vector<int> temp;
        int i = 0, k2 = k;

        if(nums.size() == 1){
            temp.push_back(nums[0]);
            return temp;
        }
        if(k == 1){
            return nums;
        }

        while(i < nums.size())
        {
            if(nums[i] > max)
            {
                max = nums[i];
            }

            if(i == (k-1))
            {
                temp.push_back(max);
                i = i - (k2 - 2);
                max = nums[i];
                k++;
            }

            if(nums[i] > max)
            {
                max = nums[i];
            }
            i++;
        }
        cout<<"result is -->"<<endl;
        for(int i = 0; i < temp.size(); i++)
        {
            cout << temp[i] << " " ;
        }

        return temp;
    }
};

int main()
{
    Solution s;
    vector<int> arr = {1,-1};
    s.maxSlidingWindow(arr, 1);

    return 0;
}

