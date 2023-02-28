#include <bits/stdc++.h>
using namespace std;

stack<int> reverseTheGroups(stack<int> &s, int n, int k) {
    if(s.empty()){
        return s;
    }

    int *arr = new int[k];
   /* int lastEl, lastSecondEl;
    lastEl = s.top();
    s.pop();

    lastSecondEl = s.top();
    s.pop();*/

    for(int i = 0; i < k; i++){
        arr[i] = s.top();
        s.pop();
    }

    reverseTheGroups(s, n, k);

    for(int i = 0; i < k; i++){
        //cout<<s.top() <<" ";
        s.push(arr[i]);
    }

    delete []arr;
   /* s.push(lastEl);
    s.push(lastSecondEl);*/

};

int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);

    reverseTheGroups(s, s.size(), 6);

    for(int i = 0; i < 6; i++){
        cout<<s.top()<<endl;
        s.pop();
    }

    return 0;
}

