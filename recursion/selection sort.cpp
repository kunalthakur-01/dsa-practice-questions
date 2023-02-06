#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution
{
public:

    /*render(int *arr, int n){
        for(int i = 0; i < n; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }*/

    void selectionSort(int *arr, int n)
    {
        if(n == 0 || n == 1)
        {
            return ;
        }


        int minIndex = 0;

        for(int i = 1; i < n; i++)
        {
            if(arr[i] < arr[minIndex]){
                minIndex = i;
            }
        }
        swap(arr[0], arr[minIndex]);

        selectionSort(arr+1, n-1);
    }
};

int main()
{
    Solution s;

    int arr[] = {6,4,6,3,5,7,2,1,5};

    int size = sizeof(arr) / sizeof(arr[0]);

    s.selectionSort(arr, size);

    for(int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}

