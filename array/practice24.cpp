#include<bits/stdc++.h>
using namespace std;

int customerSatisfaction(int n, vector<string> s1, int m, vector<string> s2)
{
    int unHappy = 0;
    int counter = 0;
    for(int i = 0; i < s1.size(); i++){
        for(int j = 0; j < s2.size(); j++){
            if(s2[j] == s1[i]){
                counter++;
                    cout<<s1[i];
            }
            if(s2[i] == s1[j]){
                break;
            }
            if(s2[i] != s1[j] && j == s2.size() - 1){
                unHappy++;
                cout<<unHappy;
            }
        }

        if(counter > 1){
            unHappy++;
        }
        counter = 0;
    }


    return unHappy;
}

int  main()
{
    vector<string> s1 = {"tax english", "crypto hindi", "tax spanish", "sf english"};
    vector<string> s2 = {"crypto hindi", "tax spanish", "crypto spanish", "crypto hindi"};
    int wentUnhappy = customerSatisfaction(4, s1, 4, s2);
    return wentUnhappy;
}


