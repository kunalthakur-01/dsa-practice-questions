#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
using namespace std;

int binaryToDecimal(string s)
{
    reverse(s.begin(), s.end());
    int total = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '1'){
            total = total + pow(2, i);
        }
    }
    cout<<total<<endl;
}

int main()
{
    binaryToDecimal("1000");

    return 0;
}

