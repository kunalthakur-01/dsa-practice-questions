#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void permute(std::string str, int index) {
     if(index >= str.length()){
        cout << str << endl;
        return;
    }
    
    for(int i = index; i < str.length(); i++){
        swap(str[index], str[i]);
        permute(str, index+1);
        swap(str[index], str[i]);
    }
}

void printPermutations(int number) {
    string str = "";
    for(int i = 1; i <= number; i++) {
        str += to_string(i);
    }
    permute(str, 0);
}


int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;
    cout << "Permutations of " << number << " are:" << std::endl;
    printPermutations(number);
    return 0;
}
