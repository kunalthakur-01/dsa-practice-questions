#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

void afterRemoving(string s1, string s2)
{
    int n = s1.length();
    for(int i = 0; i < n; i++){
        auto isFound = s2.find(s1[i]);
        if(isFound != string::npos){
            s1.erase(s1.begin() + i);
            i = -1;
        }
    }
    cout<<s1;
}

int main()
{
    afterRemoving("kunal", "kun");

    return 0;
}


