#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node* prev;
    Node(int data) {
        this -> data = data;
        this -> next = NULL;
        this -> prev = NULL;
    }
};

// print the doubly singly linked list
void print(Node* &head) {

    Node* temp = head;

    while(temp != NULL) {
        cout<< temp -> data << " ";
        temp = temp -> next;
    }
    cout<<endl;
}


int main(){
    Node* node1 = new Node(15);
 
    Node* head = node1;
    
    print(head);

    return 0;
}