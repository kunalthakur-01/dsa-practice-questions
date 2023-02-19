#include<iostream>
#include<algorithm>
using namespace std;

int decimalToBinary(int n)
{
    string s;

    if(n == 0){
        return 0;
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
    reverse(s.begin(), s.end());

    int afterConversion = stoi(s);
    return afterConversion;
}


void makeItEqual(int a, int b, int c)
{
    int num1 = 0;
    int num2 = 0;
    int counter = 0;
    c = decimalToBinary(c);

    while(a > 0 || b > 0 || c > 0){
        if((a%2 & b%2) != c%10){

            if( !(a%2) & b%2 == c%10){
                counter++;
            }
            else if(a%2 & !(b%2) == c%10){
                counter++;
            }
            else if(!(a%2) & !(b%2) == c%10){
                counter += 2;
            }
        }

        a = (a - (a % 2)) / 2;
        b = (b - (b % 2)) / 2;
        c = c/10;
    }

    cout<<counter;

}

int main()
{
    int a = 1;
    int b = 1;
    int c = 1;
    makeItEqual(a, b, c);

    return 0;
}
