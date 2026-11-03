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
    ListNode* merge(ListNode* a, ListNode* b) { // tc : O(m+n) AS:O(1)
        ListNode* dummy=new ListNode(-1);
        ListNode* i =a;
        ListNode* j=b;
        ListNode* k=dummy;
        while(i!=NULL && j!=NULL){
            if(i->val<j->val){
                k->next=i;
                i=i->next;
            }
            else{
                k->next=j;
                j=j->next;
            }
            k=k->next;
        }
        if(i==NULL) k->next=j;
        else k->next=i;
        return dummy->next;
    }
    //method 2
    ListNode* mergeKLists(vector<ListNode*>& arr) {
        if(arr.size()==0) return NULL;
        vector<ListNode*> temp;
        while(arr.size()+temp.size()>1){
            while(arr.size()>1){
                ListNode* a=arr[arr.size()-1];
                arr.pop_back();
                ListNode* b=arr[arr.size()-1];
                arr.pop_back();
                ListNode* c=merge(a,b);
                temp.push_back(c);
            }
            while(temp.size()>1){
                ListNode* a=temp[temp.size()-1];
                temp.pop_back();
                ListNode* b=temp[temp.size()-1];
                temp.pop_back();
                ListNode* c=merge(a,b);
                arr.push_back(c);
            }
            if(arr.size()==1 && temp.size()==1){
                temp.push_back(arr[0]);
                arr.pop_back();
            }
        }
        return (arr.size() != 0) ? arr[0] : temp[0];
    }
    // method 1 
    // ListNode* mergeKLists(vector<ListNode*>& arr) {
    //     if(arr.size()==0) return NULL;
    //     while(arr.size()>1){
    //         ListNode* a=arr[arr.size()-1];
    //         arr.pop_back();
    //         ListNode* b=arr[arr.size()-1];
    //         arr.pop_back();
    //         ListNode* c=merge(a,b);
    //         arr.push_back(c);
    //     }
    //     return arr[0];
    // }
};