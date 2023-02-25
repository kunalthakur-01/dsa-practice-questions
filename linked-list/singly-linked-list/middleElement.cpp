#include <bits/stdc++.h>
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

// fing length of a linked list
int getLength(Node* &head) {
    Node* temp = head;
    int cnt = 0;

    while(temp != NULL) {
        temp = temp -> next;
        cnt++;
    }

    return cnt;
}

// approach 1************************************************************************************************************************
// find middle element
// Node* middleElement(Node* head){
//     int len = getLength(head);

//     int ans = len / 2;
    
//     Node* temp = head;
//     int cnt = 0;

//     while(cnt < ans){
//         temp = temp -> next;
//         cnt++;
//     }

//     cout << temp -> data;
//     return temp;
// }



// approach 2************************************************************************************************************************
// find middle element
Node* middleElement(Node* head){
    if(head == NULL || head -> next == NULL){
        return head;
    }
    if(head -> next -> next == NULL) {
        return head -> next;
    }

    Node* slow = head;
    Node* fast = head -> next;

    while(fast != NULL) {
        fast = fast -> next;
        if(fast != NULL){
            fast = fast -> next;
        }

        slow = slow -> next;
    }

    cout<< slow -> data;
    return slow;
}



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
    insertAtPosition(head, tail, 10, 5);

    print(head);

    // cout<< "Head ->" << head -> data << endl;
    // cout<< "tail ->" << tail -> data << endl;

  

    // cout<< "Head ->" << head -> data << endl;
    // cout<< "tail ->" << tail -> data << endl;

    middleElement(head);

    return 0;
}