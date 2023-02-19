#include<iostream>
#include<vector>
#include <string>
#include <math.h>
using namespace std;
class Solution {
public:
    string reverseOneWord(string s)
    {
        string temp = "";
        for(int i = s.length() -1; i >= 0; i--){
            temp.push_back(s[i]);
        }
        return temp;
    }

    string reverseWords(string s) {
        string temp;
        string st;
        for(int i = s.length() - 1; i >= 0; i--){
                temp.push_back(s[i]);

                if(s[i] == ' ' || i == 0){
                    if(i == 0){
                        st = st + " " + reverseOneWord(temp);
                    }
                    else {
                        st = st + reverseOneWord(temp);
                    }
                    temp.clear();
                }
                if(st[0] == ' '){
                    st.erase(0, 1);
                }
                if(st[st.length() - 1] == ' '){
                    st.erase(st.length() - 1, 1);
                }
        }

        cout<<"result is:"<<endl;
        cout<<st;
    }
};

int main()
{
    string str = "my name is kunal";

    Solution s;
    s.reverseWords(str);
    return 0;
}

