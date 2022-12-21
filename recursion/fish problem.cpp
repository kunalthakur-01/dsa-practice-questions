#include <bits/stdc++.h>
using namespace std;

void print(int n, int k, vector<bool> fish)
{
    for(auto i = fish.begin() + 1; i != fish.end(); i++){
       cout<<*i<<" ";
    }
    cout<<endl;
}

int minimumNet(int n, int k, vector<bool> fish)
{
    cout<<"wtf";
   /* if(n == fish.size()){
        return 0;
    }*/

    print(n, k, fish);

    int counter = 0;

    for(int i = fish.size()-1; i >= 0; i--){
       if(fish[i] == 1){
        minimumNet(i, k, fish);
       }
    }
}

int main()
{
    vector<bool> arr = {1,0,1,1,0,0,1,1};

    //minimumNet(arr.size(), 3, arr);
    print(arr.size(), 3, arr);

    return 0;
}
