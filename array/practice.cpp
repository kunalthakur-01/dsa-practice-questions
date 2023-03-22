#include<iostream>
using namespace std;

void practice1DArray(int *arr){
    cout << arr << endl;

    for(int i = 0; i < 5; i++){
        cout<< arr[i] << " ";
    }
}

void practice2DArray(int arr[3][3]){
    cout << arr << endl;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout<< arr[i][j] << " ";
        }
        cout<< endl;
    }
}

// pass array by pointer
// void practice2DArray(int (*arr)[3]){
//     cout << arr << endl;

//     for(int i = 0; i < 3; i++){
//         for(int j = 0; j < 3; j++){
//             cout<< arr[i][j] << " ";
//         }
//         cout<< endl;
//     }
// }

int main(){
    int arr[10] = {1,5,10,15,20};
    // cout<< arr;

    practice1DArray(arr + 2);

    cout << endl;

    int arr2[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
    // cout<< arr2;
    practice2DArray(arr2);
    return 0;
}