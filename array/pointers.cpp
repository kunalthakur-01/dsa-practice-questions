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
    cout<<*&n<<endl;
    cout<<endl<<endl;

    int *k = arr;

    cout<<k<<endl;
    cout<<arr<<endl;
    cout<<arr+1;
    cout<<endl<<endl;

    int *a = new int;
    *a = 10;
    cout << *a;
    delete a;
    cout<<endl<<endl;

    int &b = n;
    cout << &b;
    
    return 0;
}

