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
        cout << "deleted " << value << endl;
    }
};

void insertNode(Node *&tail, int element, int data)
{

    // if list is empty
    if (tail == NULL)
    {
        Node *newNode = new Node(data);
        tail = newNode;
        newNode->next = newNode;
    }
    // if list is not empty
    else
    {
        Node *curr = tail;

        if(tail -> data == element) {
            Node *newNode = new Node(data);
            newNode->next = tail->next;
            curr->next = newNode;
            tail = newNode;
            return;
        }

        while (curr->data != element)
        {
            curr = curr->next;
        }

        Node *newNode = new Node(data);
        newNode->next = curr->next;
        curr->next = newNode;
    }
}

// print the circular linked list
void print(Node *&tail)
{
    Node *temp = tail;

    // empty list
    if (tail == NULL)
    {
        cout << "List is Empty " << endl;
        return;
    }

    do
    {
        tail = tail->next;
        cout << tail->data << " ";
    } while (tail != temp);

    cout << endl;
}

int main()
{
    Node *tail = NULL;

    insertNode(tail, 3, 5);
    print(tail);

    insertNode(tail, 5, 3);
    print(tail);

    insertNode(tail, 3, 1);
    print(tail);

    insertNode(tail, 3, 100);
    print(tail);

    cout<< "tail ->" << tail -> data << endl;

    return 0;
}