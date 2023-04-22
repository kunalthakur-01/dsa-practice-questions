#include<bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode* next;
    ListNode(int val) {
        this -> val = val;
        this -> next = NULL;
    }
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummy =  NULL;
    ListNode* temp=dummy;
    int carry=0;
    while(l1!=NULL || l2!=NULL || carry){
        int sum=0;
        if(l1!=NULL){
            sum+=l1->val;
            l1=l1->next;
        }
        if(l2!=NULL){
            sum+=l2->val;
            l2=l2->next;
        }
        sum+=carry;
        carry=sum/10;
        ListNode* newnode=new ListNode(sum%10);
        temp->next=newnode;
        temp=temp->next;
    }
    return dummy->next;
}

int main()
{
    ListNode* head1 = new ListNode(1);
    head1 -> next = new ListNode(3);
    head1 -> next -> next = new ListNode(5);
    head1 -> next -> next -> next = NULL;
    
    ListNode* head2 = new ListNode(2);
    head2 -> next = new ListNode(4);
    head2 -> next -> next = new ListNode(4);
    head2 -> next -> next -> next = NULL;
    
    addTwoNumbers(head1, head2);
    
    return 0;
}