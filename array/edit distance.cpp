#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
  public:
    int editDistance(string s, string t) {
        //int length = s.length() > t.length() ? s.length() : t.length();
        int counter = 0;

        if(s.length() == 0 && t.length() == 0){
            return 0;
        }
        if(t.length() == 0){
            return 1;
        }

        for(int i = 0; i < t.length(); i++){
            if(s[i] != t[i]){
                cout<<s[i];
                counter++;
                if(s[i] == t[i+1]){
                    s.insert(s.begin() + i, t[i]);
                }
                /*else if(s[i] != t[i+1]){
                    s[i] = t[i];
                }*/
                else if(s[i+1] == t[i]){
                    s.erase(s.begin() + i);
                }
                else if(s.length() == i){
                    s.push_back(t[i]);
                }
                else{
                    s[i] = t[i];
                }
            }
        }
        if(s.length() != t.length()){
            for(int i = s.length() - 1; i >= t.length(); i--){
                counter++;
                s.pop_back();
            }
        }
        cout<<s;
        return counter;
    }
};

int main()
{
    Solution s;
    int res;
    res = s.editDistance("plasma", "altruism");
    return res;
}
