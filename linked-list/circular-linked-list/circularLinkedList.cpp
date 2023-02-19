#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }
};

// print the circular linked list
void print(Node* &tail) {

    Node* temp = tail;
    
    do {

        cout<< temp -> data << " ";
        temp = temp -> next;

    } while(temp != tail);
    cout<<endl;
}


int main(){
    Node* tail = NULL;
     
    return 0;
}