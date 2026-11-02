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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* a=head->next;
        ListNode* newHead=reverseList(a); 
        a->next=head;
        head->next=NULL;
        return newHead;        
     //TC O(n) AS: O(n)   
    }
    // ListNode* reverseList(ListNode* head) {
    //     ListNode* curr=head;
    //     ListNode* prev=NULL;
    //     while(curr!=NULL){
    //         ListNode* fwd=curr->next;
    //         curr->next=prev;
    //         prev=curr;
    //         curr=fwd;
    //     }
    //     return prev;
    //TC O(n) AS: O(1) better iterative  
        
    // }
};