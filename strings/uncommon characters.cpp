#include<iostream>

using namespace std;

class Solution
{
    public:
        string UncommonChars(string A, string B)
        {
            for(int i = 0; i < A.length(); i++){
                for(int j = 0; j < B.length(); j++){
                    if(A[i] == B[j]){
                        A[i] = '';
                        B[j] = '';
                    }
                }
            }

            return string UncommonChars =  A.concat(B);

        }
};

int main()
{
    Solution s;
    s.UncommonChars("kunal", "thakur");

    return 0;
}
