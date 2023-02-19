#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        string str = "";
        string str2 = "";
        vector<string> store;
        int i = 0, j = 0;
        //for(int i = 0; i < s.length(); i++){
        while(i >= 0){
            str = str + s[i];
            auto res = find(wordDict.begin(), wordDict.end(), str);
            auto isHad = find(store.begin(), store.end(), str);
            if(res != wordDict.end()){
                /*str2 = str2 + str;
                store.push_back(str);
                str = "";*/
                if(isHad == store.end()){
                    str2 = str2 + str;
                    store.push_back(str);
                    str = "";
                }
                else if( str2.find(str) != string::npos){
                    str2 = str2 + str;
                    str = "";
                }
            }
            if(str2 == s){
                //cout<<"true";
                return true;
            }
            if(str2 == "" && i == s.length() - 1){
                //cout<<"false";
                return false;
            }
            if(i == s.length() - 1){
                str2 = "";
            }
            j++;
            i = j % s.length();
        }
        //cout<<str;
    }
};

int main()
{
    vector<string> v = { "ab","bcd","b","a"};
    Solution s;
    bool result = s.wordBreak("abcd", v);
    cout<<result;
    string ss = "applepenappl";
    /*auto res = ss.find("pen");

    if(res != string::npos){
        cout<<"yes";;
    }*/

    return 0;
}
