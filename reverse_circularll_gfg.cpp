/* Linked List Node Structure
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* reverse(Node* head) {
        Node* curr=head;
        Node* prev=NULL;
        while(curr!=NULL){
            Node* fwd=curr->next;
            curr->next=prev;
            prev=curr;
            curr=fwd;
        }
        return prev;
    }
    Node* reverseCircular(Node* head) {
        // code here
        Node* temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        Node* tail=temp;
        tail->next=NULL;
        Node* newHead = reverse(head);
        head->next = newHead;
        return newHead;
        
    }
};