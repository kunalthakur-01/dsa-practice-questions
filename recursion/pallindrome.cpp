#include<iostream>
#include<string>
using namespace std;

bool pallindrome(string s, int i, int j)
{
    if(i > j){
        return true;
    }

    if(s[i] != s[j]){
        return false;
    }
    i++;
    j--;
    return pallindrome(s, i, j);
}

int main()
{
    string s = "aba";

    cout<<"after reverse --> "<<pallindrome(s, 0, s.length()-1);

    return 0;
}

