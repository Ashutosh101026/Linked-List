#include<iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* next;
    Node(int val){
        this->val=val;
    }
};


class MyLinkedList{
    private:
    Node* head;
    Node* tail;
    int length;
    public:
    MyLinkedList(){
        head=tail=NULL;
        length=0;
    }

    void display(){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

    void InsertAtTail(int val){
        Node* n=new Node(val);
        if(length==0) head=tail=n;
        else{
            tail->next = n;
            tail=n;
        }
        length++;
    }

    void InsertAtHead(int val){
        Node* n=new Node(val);
        if(length==0) head=tail=n;
        else{
            n->next=head;
            head=n;
        }
        length++;
    }

    void InsertAtIdx(int idx, int val){
        if(idx<0 || idx>length){
            cout<<"Invalid idx"<<endl;
            return;
        }
        if(idx==0){ // insert at head
            InsertAtHead(val);
            return;
        }
        if(idx==length){//insert at tail
            InsertAtTail(val);
            return;
        }
        Node* n=new Node(val);
        Node* temp=head;
        for(int i=0;i<=idx-1;i++){
           temp=temp->next;
        }
        n->next=temp->next;
        temp->next = n;
        length++;
    }

    void RemoveAtHead(){
        if(length==0){
            cout<<"List Is Empty"<<endl;
            return;
        }
        Node* ToBeDeleted=head;
        head=head->next;
        delete ToBeDeleted;
        length--;
    }

    void RemoveAtIdx(int idx){
        if(idx<0 || idx>length){
            cout<<"Invalid idx"<<endl;
            return;
        }
        if(idx==0){
            RemoveAtHead();
            return;
        }
        Node* temp=head;
        for(int i=0;i<=idx-1;i++){
            temp=temp->next;
        }
        Node* ToBeDeleted=temp->next;
        temp->next=temp->next->next;
        if(idx==length-1) tail=temp;
        delete ToBeDeleted;
        length--;
    }

    int size(){
        return length;
    }

    int get(int idx){
        if(idx<0 || idx>=length){
            cout<<"Invalid idx"<<endl;
            return -1;
        }
        Node* temp= head;
        for(int i=0;i<=idx;i++){
            temp=temp->next;
        }
        return temp->val;
    }
};


int main(){
    MyLinkedList list;
    list.InsertAtTail(10);
    list.InsertAtTail(20);
    list.InsertAtTail(30);
    list.display();
    list.InsertAtHead(40);
    list.display();
    list.RemoveAtHead();
    list.display();
}