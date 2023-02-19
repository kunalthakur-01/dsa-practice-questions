#include<iostream>
#include<vector>
using namespace std;

int LightUptheStreet(int n, int bulbs , int range , vector <int> Checkpoints){

    /*int store1, store2;
    if( (Checkpoints[0] - range) <= 1 && (Checkpoints[Checkpoints.size() - 1] + range) >= n){
        store1 = Checkpoints[0] + range;
        store2 = Checkpoints[Checkpoints.size() - 1] - range;
        if(store2 <= store1+1){
            return 2;
        }
        else{
            return -1;
        }
    }*/

    for(int i = 0, j = Checkpoints.size() - 1; i <  Checkpoints.size(); j--, i++){

    }

}

int main()
{
    vector<int> lights = {2,4,6,8};
    int value = LightUptheStreet(10, 3, 3, lights);

    return value;
}

