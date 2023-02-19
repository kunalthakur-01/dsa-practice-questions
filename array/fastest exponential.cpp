#include<iostream>
using namespace std;

class Solution {
public:
    int fastestExponential(int x, int n, int m = 1000000007) {
        int res = 1;

        while(n > 0){
            if(n&1){
                res = (1LL * res * (x%m)) % m;
            }

            x = (1LL * (x)%m * (x)%m) % m;
            n = n>>1;
        }

        return res;
    }

};

int main()
{
    Solution s;

    return s.fastestExponential(2,10);
}

