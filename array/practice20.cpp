#include<iostream>
#include<vector>
#include<string>
#include<math.h>
using namespace std;

//convert decimal number to binary number
string decimalToBinary(int n)
{
    string s;
    int quotient;

    if(n == 0){
        return "0";
    }

    while(n > 0){
        if(n % 2 != 0){
            s.push_back('1');
        }
        else {
            s.push_back('0');
        }
        n = (n - (n % 2)) / 2;
    }
    return s;
}


//convert binary number to decimal number
int binaryToDecimal(string s)
{
    int total = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '1'){
            total = total + pow(2, i);
        }
    }
    return total;
}


//Bitwise AND operation between two numbers
int bitwiseAND(int n1, int n2)
{
    string s1 = decimalToBinary(n1);
    string s2 = decimalToBinary(n2);

    string afterAND;
    int j = 0;
    int minLength = s1.length() < s2.length() ? (s1.length() - 1) : (s2.length() - 1);
    int i = 0;
    while(i <= minLength){
        if(s1[i] == s2[i]){
            afterAND.push_back(s1[i]);
        }
        else{
            afterAND.push_back('0');
        }
        j++;
        i++;
    }
    int numb = binaryToDecimal(afterAND);
    return numb;
}


//its a ninja's question
void ninjaQuery(vector<int> arr, vector<int> queries)
{
    int ANDOperation;
    for(int i = 0; i < queries.size(); i++){

        int j = 0;
        ANDOperation = bitwiseAND(arr[j], arr[j + 1]);

        while(ANDOperation >= queries[i]){
            ANDOperation = bitwiseAND(ANDOperation, arr[j + 2]);
            j++;
        }
        if(j > 0){
            cout<<j + 1<<endl;
        }
        else{
            cout<<"0";
        }
    }
}

int main()
{
    vector<int> v = {1,2,3};
    vector<int> queries = {10};

    ninjaQuery(v, queries);

    return 0;
}
