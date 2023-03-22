#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(){
    // initialize the file object
    fstream my_file;

    string fileText = "";

    my_file.open("removeSpaceInFile.cpp", ios::in);
    if(!my_file) {
        cout<< "File not found";
    }
    else {
        char ch;
        while(1){
            my_file >> ch;
            if(my_file.eof()) break;
            fileText +=  ch;
        }
    }
    
    cout<< fileText;

    my_file.close();

    return 0;
}