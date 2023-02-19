#include<iostream>
#include<string>
using namespace std;

string reverseString(string str)
{
    string temp = "";
    for(int i = str.length() - 1, j = 0; i >= 0 && j < str.length(); i--, j++){
        temp.push_back(str[i]);
    }
    return temp;
}

void shortestPallindrome(string s)
{
    string rev;
    for(int i = s.length() - 1, j = 0; i >= 0 && j < s.length(); i--, j++){
        rev.push_back(s[i]);
    }

    string s2 = s;
    int i = s2.length() - 1, j = 0;

    while(rev != s){
        s.insert(s.begin() + j, s2[i]);

        rev.insert(rev.end() - j, s2[i]);
        i--;
        j++;
    }

    cout<<s;
}

int main()
{
    shortestPallindrome("abcd");

    return 0;
}

