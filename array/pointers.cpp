#include<bits/stdc++.h>
using namespace std;

int  main()
{
    int n = 6;
    int *p = 0;
    p = &n;
    int arr[5] = {1,2,3,4,5};

    cout<<p<<endl;
    cout<<*p<<endl;
    cout<<*&n;

    int *k = arr;

    cout<<k<<endl;
    cout<<arr<<endl;
    cout<<arr+1;
    return 0;
}

