#include<iostream>
#include<stack>
using namespace std;

bool isValid(string s) {
    int n=s.length();
    stack<char>stk;
    for(int i=0;i<n;i++){
        //if opening just push
        if(s[i]=='{' || s[i]=='(' || s[i]=='['){
            stk.push(s[i]);
        }
        else if(s[i]=='}'){
            //check if pair is found
            if(!stk.empty() && stk.top()=='{'){
                stk.pop();
            }
            else{
                stk.push(s[i]);
            }
        }
        else if(s[i]==']'){
            //check if pair is found
            if(!stk.empty() && stk.top()=='['){
                stk.pop();
            }
            else{
                stk.push(s[i]);
            }
        }
        else if(s[i]==')'){
            //check if pair is found
            if(!stk.empty() && stk.top()=='('){
                stk.pop();
            }
            else{
                stk.push(s[i]);
            }
        }
    }
    //if all are balanced than stack should be empty, return true if so
    return stk.size()==0;
    }

int main()
{
    string str = "[([]])";
    bool res = isValid(str);
    cout<<res;

    return 0;
}
