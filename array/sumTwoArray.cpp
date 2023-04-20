#include<bits/stdc++.h>
using namespace std;

vector<int> addTwoArray(vector<int> n1, vector<int> n2){
    int i = n1.size() - 1, j = n2.size() - 1;
    int sum = 0, remainder = 0;
    int carry = 0;
    vector<int> result;

    while(i >= 0 && j >= 0){
        sum = n1[i--] + n2[j--];
        if(carry > 0) sum += carry;
        remainder = sum % 10;
        result.push_back(remainder);
        sum /= 10;
        carry = sum;
    }

    while(i >= 0) {
        sum = n1[i--] + carry;
        remainder = sum % 10;
        result.push_back(remainder);
        sum /= 10;
        carry = sum;
    }

    while(j >= 0) {
        sum = n2[j--] + carry;
        remainder = sum % 10;
        result.push_back(remainder);
        sum /= 10;
        carry = sum;
    }

    reverse(result.begin(), result.end());

    return result;
}

int main() {
    vector<int> n1 = {5,8,4,4};
    vector<int> n2 = {2,5,6,4,6};

    vector<int> result = addTwoArray(n1, n2);

    for(int i = 0; i < result.size(); i++){
        cout<< result[i] <<" ";
    }
    return 0;
}