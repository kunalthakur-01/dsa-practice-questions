#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }
};

// remove duplicates from sorted linked list
void removeDuplicateFromSorted(Node* &head) {
    if(head == NULL) {
        return;
    }
    Node* curr = head;
    Node* forward = head -> next;

    while(forward != NULL) {
        if(curr -> data == forward -> data) {
            Node* nodeToDelete = forward;
            curr -> next = forward -> next;
            forward = forward -> next;
            delete(nodeToDelete);
            continue;
        }
        curr = forward;
        forward = forward -> next;
    }
}


// remove duplicates from unsorted linked list
// not optimal solution(time complexity n^2)
// for optimal solution(time complexity in n then use map but space complexity will also be n)
void removeDuplicateFromUnsorted(Node* &head) {
    if(head == NULL) {
        return;
    }
    Node* outer = head;
    Node* inner = outer -> next;
    Node* prev = NULL;

    while(outer != NULL){
        inner = outer -> next;
        prev = outer;
        while(inner != NULL){
            if(outer -> data == inner -> data) {
                Node* nodeToDelete = inner;
                prev -> next = inner -> next;
                inner = inner -> next;
                delete(nodeToDelete);
            }
            else {
                prev = inner;
                inner = inner -> next;
            }
        }
        outer = outer -> next;
    }
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
    Node* node1 = new Node(15);
 
    Node* head = node1;
    Node* tail = node1;
    // print(head);

    // insert at the begin
    insertAtHead(head, 10);
    insertAtHead(head, 10);
    insertAtHead(head, 10);
    insertAtHead(head, 5);
    // print(head);


    // insert at the end
    insertAtTail(tail, 20);
    insertAtTail(tail, 30);
    insertAtTail(tail, 30);
    // print(head);


    // insert at any position
    insertAtPosition(head, tail, 25, 5);
    print(head);

    // cout<< tail;
    removeDuplicateFromUnsorted(head);
    print(head);

    // cout<< head -> data << " ";
    return 0;
}