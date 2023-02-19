#include <bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>> &arr, int m, int n){
    for(int i = 0; i < arr.size(); i++){
        for(int j = 0; j < arr[i].size(); j++){
            if(i == m || j == n){
                arr[i][j] = 0;
            }
        }
    }
}

void findZeroes(vector<vector<int>> &arr){
    vector<vector<int>> temp = arr;
    for(int i = 0; i < arr.size(); i++){
        for(int j = 0; j < arr[i].size(); j++){
            if(arr[i][j] == 0){
                setZeroes(temp, i, j);
            }
        }
    }
    
    arr = temp;
}

int main()
{
    vector<vector<int>> arr = { {0,1,3}, {4,5,3}, {3,1,5} };
    
    findZeroes(arr);
    
    for(int i = 0; i < arr.size(); i++){
        for(int j = 0; j < arr[i].size(); j++){
            cout<<arr[i][j] << " ";
        }
        cout<<endl;
    }
    
    return 0;
}
