#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> arr, int l, int r, int k) {
        sort(arr.begin(), arr.end());

        for(int i =0 ;i < r; i++){
            if(i == k-1){
                return arr[i];
            }
        }
    }
};

int  main()
{
    Solution s;
    vector<int> v = {7,10,4,20,15};
    int res = s.kthSmallest(v, 0, 4, 4);

    return res;
}
