#include<iostream>
using namespace std;

class Solution
{
public:
    int myPow(int a, int b){
        if(b == 0){
            return 1;
        }
        if(b == 1){
            return a;
        }

        int ans = myPow(a, b/2);

        if(b % 2 == 0){
            return ans * ans;
        }
        else {
            return a * ans * ans;
        }
    }
};

int main()
{
    Solution s;

    cout<<"ans is --> "<<s.myPow(2,10);

    return 0;
}
