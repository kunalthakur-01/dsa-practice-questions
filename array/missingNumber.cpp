#include<iostream>
#include<algorithm>
using namespace std;

int missingNumber(int *arr, int n, int N){
    int sum1 = 0;
    int sum2 = 0;
    for(int i = 1; i <= N; i++){
        sum1 += i;
    }

    for(int i =0 ; i < n; i++){
        sum2 += arr[i];
    }

    return sum1 - sum2;
}

int main(){
    int arr[10] = {1,2,4,6,3,7,8,9};
    int len = 9;
    int N = 9;
    int ans = missingNumber(arr, len, N);

    cout << ans;

    return 0;
}