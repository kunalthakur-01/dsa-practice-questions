#include<iostream>
using namespace std;

int findElement(int *arr, int size, int target)
{
    if(size == 0){
        return false;
    }
    if(target == arr[0]){
        return true;
    }
    else {
        return findElement(arr+1, size-1, target);
    }
}

int main()
{
    int arr[10] = {1,2,3,4,5,6};
    int size = 6;
    int result = findElement(arr, size, 8);

    return result;
}

