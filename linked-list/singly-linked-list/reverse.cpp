#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};


// Recursively reverse
void recursivelySolve(Node* &head, Node* &curr, Node* &prev) {
    if(curr == NULL){
        head = prev;
        return;
    }

    Node* forward = curr -> next;
    recursivelySolve(head, forward, curr);
    curr -> next = prev;
} 

// another soltion with recursion
// Node* recursivelySolve(Node* head){
//     if(head == NULL || head -> next == NULL){
//         return head;
//     }

//     Node* childHead = recursivelySolve(head -> next);

//     head -> next -> next = head;
//     head -> next = NULL;

//     return childHead;
// }

void reverse(Node* &head, Node* &tail) {
    Node* curr = head;
    tail = head;
    Node* prev = NULL;
    recursivelySolve(head, curr, prev);
}


// iteratively reverse
// void reverse(Node *&head, Node *&tail)
// {
//     if (head == NULL || head->next == NULL)
//     {
//         // return head;
//         return;
//     }

//     Node *prev = NULL;
//     Node *curr = head;
//     tail = head;
//     Node *forward = NULL;

//     while (curr != NULL)
//     {
//         forward = curr->next;
//         curr->next = prev;
//         prev = curr;
//         curr = forward;
//     }
//     head = prev;
//     // return prev;
// }

// insertion at the begining of the list
void insertAtHead(Node *&head, int data)
{
    Node *temp = new Node(data);

    temp->next = head;
    head = temp;
}

// insertion at the end of the list
void insertAtTail(Node *&tail, int data)
{

    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

// insertion at any position
void insertAtPosition(Node *&head, Node *&tail, int data, int position)
{

    // insert at start
    if (position == 1)
    {
        insertAtHead(head, data);
        return;
    }

    Node *temp = head;
    int counter = 1;

    while (counter < position - 1)
    {
        temp = temp->next;
        counter++;
    }

    // insert at end
    if (temp->next == NULL)
    {
        insertAtTail(tail, data);
        return;
    }

    // insert at given position
    Node *newNode = new Node(data);
    newNode->next = temp->next;
    temp->next = newNode;
}

// print the singly linked list
void print(Node *&head)
{

    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *node1 = new Node(1);

    Node *head = node1;
    Node *tail = node1;
    print(head);

    insertAtPosition(head, tail, 2, 2);
    insertAtPosition(head, tail, 3, 3);
    insertAtPosition(head, tail, 4, 4);

    print(head);

    // cout<< "Head ->" << head -> data << endl;
    // cout<< "tail ->" << tail -> data << endl;

    reverse(head, tail);
    print(head);

    // cout<< "Head ->" << head -> data << endl;
    // cout<< "tail ->" << tail -> data << endl;

    return 0;
}