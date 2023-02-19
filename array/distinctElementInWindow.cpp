#include<iostream>
#include<vector>
using namespace std;

void distinctElement(vector<int> nums, int k)
{
    int res = 1;
    vector<int> temp;
    for(int i = 0; i <= nums.size() - k; i++){
        for (int j = i+1; j < i + k; j++) {
            int p = 0;
            for (p = i; p < j; p++){
                if (nums[j] == nums[p])
                    break;
            }

            if (j == p){
                res++;
            }
        }
        temp.push_back(res);
        res = 1;
    }

    cout<<"result is -->"<<endl;
    for(int i = 0; i < temp.size(); i++){
        cout<<temp[i]<<" ";
    }
}

int main()
{
    vector<int> arr = {1,2,4,4};
    distinctElement(arr, 2);

    return 0;
}
