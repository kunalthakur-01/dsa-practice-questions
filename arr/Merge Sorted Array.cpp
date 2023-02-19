#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
        int j = 0;
        for(int i = 0; i < m+n; i++){
            if(nums1[i] > nums2[j] && i < m && nums1[i] != 0){
                swap(nums1[i], nums2[j]);
            }

            if(i >= m || nums1[i] == 0){
                nums1[i] = nums2[j];
                j++;
            }
        }
        for(int i = 0; i < m+n; i++){
            cout<<nums1[i]<<endl;
        }
    }
};

int main()
{
    Solution s;
    vector<int> v1 ={1,2,3,0,0,0};
    vector<int> v2 ={2,5,6};
    s.merge(v1, v1.size(), v2, v2.size());

    return 0;
}

