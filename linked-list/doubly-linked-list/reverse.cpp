#include <bits/stdc++.h>
using namespace std;

class Node {
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

void reverse(Node* &head, Node* &tail){
    if(head == NULL){
        return;
    }

    Node* prevNode = NULL;
    Node* currNode = head;
    tail = head;

    while(currNode != NULL){
        prevNode = currNode;
        currNode = currNode -> next;
        prevNode -> next = prevNode -> prev;
        prevNode -> prev = currNode;
    }

    head = prevNode;
}

// insertion at the begining of the list
void insertAtHead(Node* &head, Node* &tail, int data) {
    Node* temp = new Node(data);

    if(head == NULL) {
        head = temp;
        tail = temp;
    }
    else{
        temp -> next = head;
        head -> prev = temp;
        head = temp;
    }

}


// insertion at the end of the list
void insertAtTail(Node* &tail, Node* &head, int data) {
    Node* temp = new Node(data);

    if(tail == NULL) {
        tail = temp;
        head = temp;
    }
    else {
        tail -> next = temp;
        temp -> prev = tail;
        tail = temp;
    }

}


// insertion at any position
void insertAtPosition(Node* &head, Node* &tail, int data, int position) {

    // insert at start
    if(position == 1) {
        insertAtHead(head, tail, data);
        return;
    }

    Node* temp = head;
    int counter = 1;

    while(counter < position - 1) {
        temp = temp -> next;
        counter++;
    }

    // insert at end
    if(temp -> next == NULL) {
        insertAtTail(tail, head, data);
        return;
    }

    // insert at given position
    Node* newNode = new Node(data);
    newNode -> next = temp -> next;
    temp -> next -> prev = newNode;
    newNode -> prev = temp;
    temp -> next = newNode;

}


// print the singly linked list
void print(Node* &head) {

    Node* temp = head;

    while(temp != NULL) {
        cout<< temp -> data << " ";
        temp = temp -> next;
    }
    cout<<endl;
}


int main(){
    // Node* node1 = new Node(15);
 
    Node* head = NULL;
    Node* tail = NULL;

    // insert at the begin
    insertAtHead(head, tail, 10);
    insertAtHead(head, tail, 5);

    // insert at the end
    insertAtTail(tail, head, 20);
    insertAtTail(tail, head, 30);

    // insert at any position
    insertAtPosition(head, tail, 25, 4);
    print(head);

    reverse(head, tail);

    print(head);
    return 0;
}