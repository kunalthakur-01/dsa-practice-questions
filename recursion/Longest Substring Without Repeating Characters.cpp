#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0, store = 0, currCounter = 1;
        for(int i = 0; i < s.length(); i++){
            for(int j = i - 1; j >= start; j--){
                currCounter++;
                if(s[i] == s[j]){
                    start = j + 1;
                    currCounter--;
                    break;
                }
            }

            if(currCounter > store){
                store = currCounter;
            }
            currCounter = 1;
        }

        return store;
    }
};

int main()
{
    Solution s;
    string str = "abcdbaef";
    cout<<"ans is --> "<<s.lengthOfLongestSubstring(str);
}
