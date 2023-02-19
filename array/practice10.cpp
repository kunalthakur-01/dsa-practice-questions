#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        int quotient = 0;
        int counter = 0;
        int rem = 0;
        vector<int> arr;
        for(int i = 0; i <= n; i++){
            quotient = i;
            while(quotient != 0){
                if(quotient % 2 == 0){
                    rem = quotient % 2;
                    quotient = (quotient - rem) / 2;
                }
                else {
                    rem = quotient % 2;
                    quotient = (quotient - rem) / 2;
                    counter++;
                }
            }
            arr.push_back(counter);
            counter = 0;
        }

        return arr;
    }
};

int main()
{
    Solution s;
    vector<int> res = s.countBits(8);

    cout<<"result is:"<<endl;
    for(int i = 0 ;i < res.size(); i++){
        cout<<res[i]<<" ";
    }


    return 0;
}
