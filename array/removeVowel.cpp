#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
    string v = "my name is kunal";
    int counter= 0;

    for(int i = 0; i < v.length(); i++){
        if(v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u' || v[i] == 'A' || v[i] == 'E' || v[i] == 'I' || v[i] == 'O' || v[i] == 'U'){
            counter++;
        }
        else{
            v[i - counter] = v[i];
            cout<<v[i];
        }
    }

    //cout<<v;

    return 0;
}
