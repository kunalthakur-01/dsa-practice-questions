#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int flag1 = 0;
        int flag2 = 0;
        int flag3 = 0;
        if(s.length() == 0){
            return false;
        }
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '('){
                flag1++;
                if(s[i+1] == ']' || s[i+1] == '}'){
                    return false;
                }
            }
            else if(s[i] == '['){
                flag2++;
                if(s[i+1] == ')' || s[i+1] == '}'){
                    return false;
                }
            }
            else if(s[i] == '{'){
                flag3++;
                if(s[i+1] == ')' || s[i+1] == ']'){
                    return false;
                }
            }
            else if(s[i] == ')' && flag1){
                flag1--;
            }
            else if(s[i] == ']' && flag2){
                flag2--;
            }
            else if(s[i] == '}' && flag3){
                flag3--;
            }
            else {
                return false;
            }
            //return false;
        }
        if(!flag1 && !flag2 && !flag3){
            return true;
        }
        return false;
    }
};

int main()
{
    Solution s;
    string str = "[([]])";
    bool res = s.isValid(str);

    cout<<res;

    return 0;
}
