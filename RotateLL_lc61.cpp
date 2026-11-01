/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int length(ListNode* head){
        int len=0;
        ListNode* temp=head;
        while(temp!=NULL){
            temp=temp->next;
            len++;
        }
        return len;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL) return head;
        int n=length(head);
        k=k%n;
        if(k==0) return head;
        ListNode* temp=head;
        ListNode* a=NULL;
        ListNode* b=NULL;
        ListNode* c=NULL;
        for(int i=1;i<=n;i++){
            if(i==n-k) a=temp;
            if(i==n-k+1) b=temp;
            if(i==n) c=temp;
            temp = temp->next; 
        }
        a->next=NULL;
        c->next=head;
        return b;
    }
};