#include<iostream>
using namespace std;

class Solution {
    int m = 1000000007;
public:
    int fastestExponential(int x, int n) {
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

    int countGoodNumbers(long long n) {
        n = n-1;
        int num5 = 0;
        int num4 = 0;
        int res;
        int res5;
        int res4;
        if(n&1){
            num5 = (n / 2) + 1;
            num4 = (n / 2) + 1;
            res5 = fastestExponential(5,num5);
            res4 = fastestExponential(4,num4);

            res = (1LL * res5 * res4) % m;
            return res;
        }
        else {
            num4 = (n / 2);
            num5 = (n / 2) + 1;
            res5 = fastestExponential(5,num5);
            res4 = fastestExponential(4,num4);

            res = (1LL * res5 * res4) % m;
            return res;
        }
    }

};

int main()
{
    Solution s;

    return s.countGoodNumbers(806166225460393);
}
