#include<iostream>
using namespace std;

long long largestFactorial(long long n)
{
    int m = 1000000007;
    int fact = 1;
    for(int i = 1; i <= n; i++){
        fact = (1LL * fact * i) % m;
    }

    cout<<fact;
    return fact;
}

int main()
{
    int fact = largestFactorial(10000000000);
    return 0;
}
