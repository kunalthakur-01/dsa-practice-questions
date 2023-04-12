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


// Approach-1 (using map) not so good bec space complexity is high
bool detectLoop(Node* head)
{
    if(head == NULL) return false;

    map<Node*, bool> visited;

    Node* temp = head;

    while(temp != NULL){
        if(visited[temp]) {
            return true;
        }

        visited[temp] = true;
        temp = temp -> next;
    }

    return false;
}



int main(){
    return 0;
}