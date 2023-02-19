#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

string binaryShopping(string S, int P)
{
    int counter = 0;

    /*if(S.size() == 1){
        cout<<"1";
    }*/
    for(int i = S.size() - 1; i >= 0; i--) {
        if(S[i] == '1'){
            S[i] = '0';
            counter++;
            if(counter == 2){
                break;
            }
        }
    }

    cout<<S;
}

int main()
{
    string s = "1";
    binaryShopping(s, 5);

    return 0;
}

