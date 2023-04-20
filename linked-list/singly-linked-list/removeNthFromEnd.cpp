/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode* next;
    ListNode(int data) {
        this -> val = data;
        this -> next = NULL;
    }
};

ListNode* removeNthFromEnd(ListNode* &head, int n) {
    if(head == NULL){
        return head;
    }
    
    ListNode* temp = head;
    int count = 0;

    while(temp != NULL){
        temp = temp -> next;
        count++;
    }
        
    int position = count - n;
    
    if(position == 0){
        head = head -> next;
        return head;
    }

    temp = head;
    count = 1;

    
    while(count < position){
        temp = temp -> next;
        count++;
    }
    
    temp -> next = temp -> next -> next;
    return head;
}

void print(ListNode* &head) {

    ListNode* temp = head;

    while(temp != NULL) {
        cout<< temp -> val << " ";
        temp = temp -> next;
    }
    cout<<endl;
}

int main()
{
    ListNode* head = new ListNode(1);
    head -> next = new ListNode(2);
    head -> next -> next = new ListNode(3);
    head -> next -> next -> next = new ListNode(4);
    head -> next -> next -> next -> next = new ListNode(5);
    head -> next -> next -> next -> next -> next = new ListNode(6);
    head -> next -> next -> next -> next -> next -> next = NULL;

    print(head);
    
    head = removeNthFromEnd(head, 6);

    print(head);

    return 0;
}
