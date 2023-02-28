#include <bits/stdc++.h>
using namespace std;

string encodeString(string &s, int n)
{
    int temp = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
            temp = int(s[i]);
            s[i] = (char)temp + 1;
        }
        else{
            temp = int(s[i]);
            s[i] = (char)temp - 1;
        }
    }
}

int main()
{
    string s = "gjmf";
    encodeString(s, s.length());

    cout<<s;

    return 0;
}
