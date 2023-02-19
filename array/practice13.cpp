#include<iostream>
#include<vector>
using namespace std;

long long threeWaySplit(int n, vector<int> arr){
    int sumi = 0;
    int sumj = 0;
    int maxSum;
    int j;
    for(int i = 0; i < n; i++){

        sumi = sumi + arr[i];
        j = n - 1;

        while(i < j){
            sumj = sumj + arr[j];

            if(sumj == sumi){
                maxSum = sumi;
                break;
            }
            j--;
        }

        if(sumi != sumj){
            sumj = 0;
        }
    }


    cout<<maxSum;
}

int main()
{
    vector<int> v = {16, 45, 78, 34, 22, 73 ,83 ,74 ,30 ,80 ,99 ,74 ,30 ,94, 24, 65, 60 ,66 ,81 ,99 ,89 ,63 ,52 ,74 ,28 ,96 ,25 ,56 ,17 ,8 ,55, 11 ,44, 44, 85, 59 ,99 ,49 ,46, 99, 94, 21, 36, 67, 98, 71, 46, 94, 65, 22, 78, 53 ,34 ,41 ,54, 77,
};
    threeWaySplit(7,v);

    return 0;
}
