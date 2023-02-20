#include<bits/stdc++.h>
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

Node* reverse(Node* &head){
    if(head == NULL || head -> next == NULL) {
        return head;
    }

    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;

    while(curr != NULL) {
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

// insertion at the begining of the list
void insertAtHead(Node* &head, int data) {
    Node* temp = new Node(data);

    temp -> next = head;
    head = temp;
}


// insertion at the end of the list
void insertAtTail(Node* &tail, int data) {

    Node* temp = new Node(data);
    tail -> next = temp;
    tail = temp;
}


// insertion at any position
void insertAtPosition(Node* &head, Node* &tail, int data, int position) {

    // insert at start
    if(position == 1) {
        insertAtHead(head, data);
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
        insertAtTail(tail, data);
        return;
    }

    // insert at given position
    Node* newNode = new Node(data);
    newNode -> next = temp -> next;
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
    Node* node1 = new Node(1);
 
    Node* head = node1;
    Node* tail = node1;
    print(head);

    insertAtPosition(head, tail, 2, 2);
    insertAtPosition(head, tail, 3, 3);
    insertAtPosition(head, tail, 4, 4);

    print(head);

    reverse(head);

    print(head);
    return 0;
}