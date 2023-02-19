#include<iostream>
#include<vector>
using namespace std;

int isPresent(vector<int> nums, int target)
{
    int digits = 0;
    int rem = target % 10;
    int counter = 0;
    for(int i = 0; i < 10; i++){
        if(target == 0){
            continue;
        }

        if(rem == i && nums[i]){
            target = target / 10;
            rem = target % 10;
            i = 0;
            digits++;
            continue;
            //counter++;
        }
        if(i == 9){
            counter++;
        }
    }

    if(!(counter > 0)){
        return digits;
    }

    return 0;
}

int calculateNumber(vector<int> arr, int n)
{
    int flag;
    int totalClick = 0;
    if(isPresent(arr, n)){
        return isPresent(arr, n) + 1;
    }
    for(int i = 9; i > 1; i--){
        if(n % i == 0 && arr[i]){
            totalClick++;
            flag = isPresent(arr, (n / i));
            if(flag){
                totalClick = totalClick + flag;
                return totalClick + 2;
            }
        }
    }

    return -1;
}

int main()
{
    vector<int> arr = {0,1,1,1,0,0,1,1,1,0};
    int res = calculateNumber(arr, 57);
    //int res2 = isPresent(arr, 12);

    return res;
}
