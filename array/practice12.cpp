#include<iostream>
#include<vector>
using namespace std;

long long appleAndCoupon(int n, int m, vector<int> arr){
    for(int i = 0; i < n - 1; i++){
        int minIndex = i;

        for(int j = i+1; j < n; j++){

            if(arr[j] < arr[minIndex]) minIndex = j;
        }
        swap(arr[minIndex], arr[i]);
    }

    int sum = 0;
    for(int i = 0; i < n; i++){
        if(i == (n - m)){
            continue;
        }
        sum = sum + arr[i];
    }

    cout<<sum;

}

int main()
{
    vector<int> v = {5,2,4,1,3};
    appleAndCoupon(5,3, v);

    return 0;
}
