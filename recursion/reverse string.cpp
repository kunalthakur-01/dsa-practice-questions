#include<iostream>
#include<string>
using namespace std;

string reverseString(string s, int n)
{
    if(n == s.length()){
        return "";
    }
    return reverseString(s, n = n+1) + s[n];
}

int main()
{
    string s = "naman";

    cout<<"after reverse --> "<<reverseString(s, 0);

    return 0;
}
