#include<iostream>
#include<algorithm>
using namespace std;

void moveNegAndPos(int *arr, int n){
    int p1 = 0;
    int p2 = n - 1;
    while (p1 < p2)
    {
        if(arr[p1] > 0 && arr[p2] < 0){
            swap(arr[p1], arr[p2]);
            p1++;
            p2--;
        }
        else if(arr[p1] < 0) p1++;
        else if(arr[p2] > 0) p2--;
    }
}

int main(){
    int arr[10] = {-4,6,-3,8,-9,7,-1,3,-2};
    moveNegAndPos(arr, 9);

    for(int i =0 ; i < 9; i++){
        cout << arr[i] << " ";
    }

    return 0;
}