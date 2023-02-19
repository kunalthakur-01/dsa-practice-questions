#include <bits/stdc++.h>
using namespace std;

void pascalTriangle(int n){
    int arr[n][(n*2) - 1];
    int k;

    for(int i = 0; i < n; i++){
        k = (n-i) + 1;
        for(int j = 0; j < (n*2) - 1; j++){
            if(j == (n-i) - 1){
                arr[i][j] = 1;
                cout<<1;
            }
            else if(j == (n+i) - 1){
                arr[i][j] = 1;
                cout<<1;
            }
            else if(i > 1 && j == k){
                arr[i][j] = arr[i-1][j-1] + arr[i-1][j+1];
                k += 2;
                cout<<arr[i][j];
            }
            else{
                arr[i][j] = 0;
                // cout<<arr[i][j];
                cout<<" ";
            }
        }
        cout<<endl;
    }
    
    // for(int i = 0; i < n; i++){
    //   for(int j = 0; j < (n*2) - 1; j++){
    //       cout<<arr[i][j];
    //     } 
    //     cout<<endl;
    // }
}

int main()
{
    pascalTriangle(6);

    return 0;
}
