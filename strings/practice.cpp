#include<iostream>
using namespace std;

void practice(char *ch){
    cout<< &ch<<endl;
    cout<< ch;
}

int main(){
    char ch[10];
    cout << "Enter your name:-->";
    cin >> ch;
    cout<<ch <<endl;

    practice(ch);
    return 0;
}