#include<iostream>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {

        int total = 0;

        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'I'){
                if(s[i+1] == 'V'){
                    total = total + 4;
                    i = i+1;
                }
                else if(s[i+1] == 'X'){
                    total = total + 9;
                    i = i+1;
                }
                else{
                    total = total + 1;
                }
            }
            else if(s[i] == 'X'){
                if(s[i+1] == 'L'){
                    total = total + 40;
                    i = i+1;
                }
                else if(s[i+1] == 'C'){
                    total = total + 90;
                    i = i+1;
                }
                else{
                    total = total + 10;
                }
            }
            else if(s[i] == 'C'){
                if(s[i+1] == 'D'){
                    total = total + 400;
                    i = i+1;
                }
                else if(s[i+1] == 'M'){
                    total = total + 900;
                    i = i+1;
                }
                else{
                    total = total + 100;
                }
            }
            else{
                if(s[i] == 'V') total = total + 5;
                if(s[i] == 'L') total = total + 50;
                if(s[i] == 'D') total = total + 500;
                if(s[i] == 'M') total = total + 1000;
            }
        }
        cout<<total;
    }
};

int main()
{
    Solution s;
    s.romanToInt("III");
}
