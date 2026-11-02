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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* dummy1= new ListNode(-1);
        ListNode* dummy2= new ListNode(-1);
        ListNode* temp=head;
        ListNode* temp1=dummy1;
        ListNode* temp2=dummy2;
        int idx=1;
        while(temp!=NULL){
            if(idx%2==1){
                temp1->next=temp;
                temp1=temp;
            }
            else{
                temp2->next=temp;
                temp2=temp;
            }
            temp=temp->next;
            idx++;
        }
        temp1->next=NULL;
        temp2->next=NULL;
        temp1->next=dummy2->next;
        return dummy1->next;
        
    }
};