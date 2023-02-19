#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string decimalToBinary(int n)
{
    string s;

    if(n == 0){
        return "0";
    }

    while(n > 0){
        if(n % 2 != 0){
            s.push_back('1');
        }
        else {
            s.push_back('0');
        }
        n = (n - (n % 2)) / 2;
    }
    reverse(s.begin(), s.end());
    return s;
}


int main()
{
    string str = decimalToBinary(2);
    cout<<str;

    return 0;
}

