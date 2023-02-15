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

    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "deleted " << value <<endl;
    }
};

// delete from the given positon
void deleteFromPositon(Node *&head, Node *&tail, int position) {

    // delete from the first or start position
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        
        temp -> next = NULL;
        delete temp;
    }

    // delete from the middle or last node
    else
    {
        Node *curr = head;
        Node *prev = NULL;
        int counter = 1;

        while (counter < position)
        {
            prev = curr;
            curr = curr -> next;
            counter++;
        }

        if(curr -> next == NULL) {
            prev -> next = curr -> next;
            curr -> next = NULL;
            tail = prev;
            delete curr;
            return;
        }

        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
    }
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
    Node *node1 = new Node(15);

    Node *head = node1;
    Node *tail = node1;

    // insert at the begin
    insertAtHead(head, 10);
    print(head);

    // insert at the end
    insertAtTail(tail, 20);
    print(head);

    // insert at any position
    insertAtPosition(head, tail, 25, 4);
    print(head);

    deleteFromPositon(head, tail, 3);
    print(head);

    return 0;
}