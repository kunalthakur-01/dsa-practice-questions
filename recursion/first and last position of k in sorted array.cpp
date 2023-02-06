#include<iostream>
#include<vector>
using namespace std;

int firstPos(vector<int> &arr, int start, int end, int target, int ans)
{

    int mid = start + (end-start) / 2;
    if(start > end){
        return ans;
    }

    if(arr[mid] == target){
        ans = mid;
        end = mid - 1;
        return firstPos(arr, start, end, target, ans);
    }
    if(target > arr[mid]){
        start = mid +1;
        return firstPos(arr, start, end, target, ans);
    }
    if(target < arr[mid]){
        end = mid-1;
        return firstPos(arr, start, end, target, ans);
    }
}

int lastPos(vector<int> &arr, int start, int end, int target, int ans)
{

   int mid = start + (end-start) / 2;
   if(start > end){
        return ans;
    }

    if(arr[mid] == target){
        ans = mid;
        start = mid + 1;
        return lastPos(arr, start, end, target, ans);
    }
    if(target > arr[mid]){
        start = mid + 1;
        return lastPos(arr, start, end, target, ans);
    }
    if(target < arr[mid]){
        end = mid-1;
        return lastPos(arr, start, end, target, ans);
    }
}

int main()
{
    vector<int> arr = {5,7,7,8,8,10};
    int k = 8;
    cout<<"first position of "<<k<<" is at "<<firstPos(arr,0, arr.size()-1, k, -1)<<endl;
    cout<<"last position of "<<k<<" is at "<<lastPos(arr,0, arr.size()-1, k, -1);

    return 0;
}


