#include<iostream>
#include<vector>
#include<assert.h>
using namespace std;

/*class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> expectedArr;
        int counter = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] != nums[i + 1]){
                expectedArr.push_back(nums[i]);
                nums[counter] = nums[i];
                counter++;
            }
        }


        int k = expectedArr.size();
        for(int i = 0; i < expectedArr.size();i++)
        {
           if(nums[i] != expectedArr[i]){
                return 0;
           }
        }
        return k;
    }
};

int main()
{
    Solution s;
    vector<int> arr = {1,1,2,2,3};
    int result = s.removeDuplicates(arr);
    cout<<result;
}*/
class practice{
public:
    vector<int> display(vector<int> &num)
    {
        for(int i = 0; i < num.size(); i++){
            cout<<num[i];
        }
        return num;
    }
};

int main()
{
    int n = -10;
    unsigned int num = -10;
    cout<<n;
    cout<<num;
    cout<<INT_MAX;
    vector<int> vec1;
    int arr[10];

    cout<<"enter the total element:";
    cin>>n;

    for(int i = 0; i< n; i++){
        cin>>arr[i];
        vec1.push_back(arr[i]);
    }


    practice p;
    vec1 = p.display(vec1);




    return 0;


}
