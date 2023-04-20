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



void insertNode(Node *&head, int element, int data)
{

    // if list is empty
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        newNode->next = newNode;
    }
    // if list is not empty
    else
    {
        Node *curr = head;

        if(head -> data == element) {
            Node *newNode = new Node(data);
            newNode->next = head->next;
            curr->next = newNode;
            head = newNode;
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
void print(Node *&head)
{
    Node *temp = head;

    // empty list
    if (head == NULL)
    {
        cout << "List is Empty " << endl;
        return;
    }

    do
    {
        cout << head->data << " ";
        head = head->next;
    } while (head != temp);

    cout << endl;
}

void splitTheList(Node* &head) {
    Node* slow = head;
    Node* fast = head -> next;

    Node* head1 = head;
    Node* head2 = NULL;
    Node* prev = NULL;

    while(fast != head) {
        prev = fast;
        fast = fast -> next;

        if(fast -> next == head){
            prev = fast;
        }

        if(fast != head) {
            fast = fast -> next;
        }

        slow = slow -> next;
    }

    head2 = slow -> next;
    slow -> next = head;
    
    if(fast -> next == head) {
        fast -> next = head2; 
    }

    if(fast == head) {
        prev -> next = head2;
    }

    print(head1);
    print(head2);

}

int main()
{
    Node *head = NULL;

    insertNode(head, 3, 5);
    print(head);

    insertNode(head, 5, 3);
    print(head);

    insertNode(head, 3, 1);
    print(head);

    insertNode(head, 3, 100);
    // insertNode(head, 3, 20);
    print(head);

    cout<< "head ->" << head -> data << endl;
    splitTheList(head);

    return 0;
}