#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int s = 0;
        int e = arr.size() - 1;
        int mid = s + (e - s) / 2;

        while(s <= e){
            if(arr[mid+1] < arr[mid] && arr[mid-1] < arr[mid] ){
                return arr[mid+1];
            }
            else if(arr[mid+1] > arr[mid]){
                s = mid + 1;
            }
            else if(arr[mid+1] < arr[mid]){
                e = mid - 1;
            }
            mid = s + (e - s) / 2;
        }
        return arr[mid+1];
    }
};

int main()
{
    vector<int> v = {7,8,3,4,5};

    int res;
    Solution s;
    res = s.peakIndexInMountainArray(v);
    cout<<res;

    return 0;
}
