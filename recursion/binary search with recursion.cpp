
#include<iostream>
using namespace std;

int findElement(int *arr, int start, int end, int target)
{

    int mid = start + (end-start) / 2;

    if(start > end){
        return false;
    }
    if(arr[mid] == target){
        return true;
    }
    if(target > arr[mid]){
        start = mid +1;
        return findElement(arr, start, end, target);
    }
    if(target < arr[mid]){
        end = mid-1;
        return findElement(arr, start, end, target);
    }
}

int main()
{
    int arr[10] = {1,2,3,4,5,6};
    int size = 6;
    bool result = findElement(arr,0, size-1, 36);
    cout<<result;

    return 0;
}

