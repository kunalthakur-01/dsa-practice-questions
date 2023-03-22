#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void removeComments(string &file){
    for(int i = 0; i < file.length(); i++){
        if(file[i] == ' '){
            return;
        }
        cout<< file[i];
    }
}

int main(){
    // initialize the file object
    fstream my_file;

    string fileText = "";

    my_file.open("removeSpaceInFile.cpp", ios::in);
    if(!my_file) {
        cout<< "File not found";
    }
    else {
        string ch;
        while(1){
            getline(my_file, ch);
            if(ch == ""){
                cout<< "empty line" << endl;
            }
            if(my_file.eof()) break;
            fileText +=  ch;
        }
    }
    
    // cout<< fileText;

    // removeComments(fileText);

    my_file.close();

    return 0;
}