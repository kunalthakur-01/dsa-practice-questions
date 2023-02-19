#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int classTest(int n, vector<int> &a, int k) {
    int marks;
    sort(a.begin(), a.end());

    cout<<a[n-k];
}

int main()
{
    int n = 4;
    vector<int> a = {1,1,2,2};

    int k = 3;

    classTest(n, a, k);

    return 0;
}
