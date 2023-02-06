#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> temp;

        string result;

        for(int i = 0; i < path.length(); i++){
            if(temp.top() == "/"){
                // temp.push(path[i]);
            }
        }

    }
};

int main()
{
    Solution s;
    s.simplifyPath("/hello/");

    return 0;
}
