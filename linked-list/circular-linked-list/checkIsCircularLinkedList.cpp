#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

bool isCircular(Node *head)
{
   Node* curr = head;
  
   while(curr != NULL){
       if(curr -> next == head){
           return true;
       }
       curr = curr -> next;
   }
   
   return false;
}

int  main(){
    Node* head = NULL;
    isCircular(head);
    return 0;
}