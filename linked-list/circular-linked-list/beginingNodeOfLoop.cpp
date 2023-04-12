#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* floydDetectLoop(Node* head)
{
    if(head == NULL) return NULL;

    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast != NULL){
        fast = fast -> next;
        if(fast != NULL) {
            fast = fast -> next;
        }

        if(slow == fast){
            return slow;
        }

        slow = slow -> next;
    }

    return NULL;
}

// get the begining node of the loop in linked list
Node* getStartingNodeOfLoop(Node* head){
    Node* intersection = floydDetectLoop(head);

    Node* slow = head;

    while(slow != intersection){
        slow = slow -> next;
        intersection = intersection -> next;
    }

    return slow;
}

int main(){
    Node* head = NULL;

    getStartingNodeOfLoop(head);

    return 0;
}