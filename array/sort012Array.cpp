#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int arr[] = {0,2,1,2,0,0,2,1,2,1,0};
    int n = sizeof arr / sizeof arr[0];

    int zeros = 0, ones = 0, twos = 0;

    for(int i = 0; i < n; i++) {
        if(arr[i] == 0) zeros++;
        if(arr[i] == 1) ones++;
        if(arr[i] == 2) twos++;
    }

    for(int i = 0; i < n; i++) {
        if(zeros) {
            arr[i] = 0; 
            zeros--;
        }
        else if(ones) {
            arr[i] = 1; 
            ones--;
        }
        else if(twos) {
            arr[i] = 2;
            twos--;
        } 
    }

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

