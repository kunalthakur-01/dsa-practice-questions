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


void reverseGroup(Node *&head, Node *&tail)
{
    if (head == NULL || head -> next == NULL)
    {
        // return head;
        return;
    }

    Node *prev = NULL;
    Node *curr = head;
    tail = head;
    Node *forward = NULL;

    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    head = prev;
    // cout<< head -> data << " " << tail -> data;
}

void reverseInKGroup(Node * &head, Node * &tail, int k){
    Node* temp = head;
    Node* tempHead = head;
    Node* tempTail = tail;
    int count = 1;

    while(temp != NULL){
            // cout<< tempHead -> data << " " << tempTail -> data;
        if(count == 1){
            cout<< temp -> data << " ";
            tempHead = temp;
        }
        if(count == k){
            count = 1;
            tempTail = temp;
            // reverseGroup(tempHead, tempTail);
            temp = temp -> next;
            continue;
        }
        temp = temp -> next;
        count++;
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

    // insert at the begin
    insertAtHead(head, 10);
    insertAtHead(head, 5);


    // insert at the end
    insertAtTail(tail, 20);
    insertAtTail(tail, 25);
    insertAtTail(tail, 30);

    print(head);

    reverseInKGroup(head, tail, 2);

    // print(head);
    return 0;
}