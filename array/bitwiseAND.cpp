#include<iostream>
#include<vector>
#include<string>
#include<math.h>
#include<algorithm>
using namespace std;

string bitwiseAND(string s1, string s2)
{
    //reverse(s1.begin(), s1.end());
    //reverse(s2.begin(), s2.end());
    string afterAND;
    int j = 0;
    int minLength = s1.length() < s2.length() ? (s1.length() - 1) : (s2.length() - 1);
    int i = 0;
    while(i <= minLength){
        if(s1[i] == s2[i]){
            afterAND.push_back(s1[i]);
        }
        else{
            afterAND.push_back('0');
        }
        j++;
        i++;
    }
    cout<<afterAND;
}

int main()
{
    bitwiseAND("1111", "1110");

    return 0;
}
