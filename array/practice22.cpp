#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void findMentor(int n, vector<int> arr)
{
    vector<int> res;
    vector<int> temp(arr);
    sort(temp.begin(), temp.end());

    for(int i = 0; i < n; i++){
        for(int j = n - 1; j >= 0; j--){
            if(arr[i] != temp[j]){
                if(temp[j] <= 2 * arr[i]){
                    res.push_back(temp[j]);
                    break;
                }
            }
            if(j == 0){
                res.push_back(-1);
            }
        }
    }
    for(int i = 0; i < n; i++){
        cout<<res[i]<<endl;
    }
}

int main()
{
    vector<int> v ={2500, 1200};
    findMentor(2, v);

    return 0;
}
