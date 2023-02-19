#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void findPrevSmaller(vector<int> arr)
    {
        vector<int> v;
        v.push_back(-1);
        int counter = 0;
        for(int i = 0; i < arr.size(); i++){
            for(int j = i - 1; j >= 0; j--){
                if(arr[j] < arr[i]){
                    counter++;
                    v.push_back(arr[j]);
                    break;
                }
                if(j == 0 && arr[j] > arr[i]){
                v.push_back(-1);
            }

            }
            if(counter == 0 && i != 0){
                v.push_back(-1);
                counter = 0;
            }
        }

        cout<<"result is -> "<<endl;
        for(int i = 0; i < v.size(); i++){
            cout<<v[i]<<" ";
        }
    }

};

int main()
{
    Solution s;
    vector<int> v = {5, 7, 4, 9, 8, 10};
    s.findPrevSmaller(v);

    return 0;
}

