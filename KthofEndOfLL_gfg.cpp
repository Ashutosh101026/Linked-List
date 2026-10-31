/* Structure of Linked List Node
class Node {
  public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
}; */

class Solution {
  public:
    int getKthFromLast(Node* head, int k) {
        // code here
        int len=0;
        Node* temp=head;
        while(temp!=NULL){
                temp=temp->next;
                len++;
        }
        temp=head;
        if(k>len) return -1;
        for(int i=1;i<=len-k;i++){
            temp=temp->next;
        }
        return temp->data;
    }
};