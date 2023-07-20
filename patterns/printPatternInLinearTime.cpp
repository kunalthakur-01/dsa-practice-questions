#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    string temp;
    // *
    // **
    // ***
    // ****
    // *****
    for(int i = 0; i < 5; i++) {
        temp += "*";
        s += temp;
        s += '\n';
    }
    
    cout << s;

    return 0;
}

