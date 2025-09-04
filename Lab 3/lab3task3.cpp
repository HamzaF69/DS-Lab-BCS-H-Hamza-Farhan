#include <iostream>
#include <string>
using namespace std;

class Node{
    public:
    int val;
    Node *next;
    Node (int v){
        val=v;
        next=nullptr;
    }
};



class LinkList{
    Node *head;
    Node *tail;
    int length;
    public:
    LinkList(){
        head=tail=nullptr;
        length=0;
    }

    void pushBack(int v){
        Node *newNode= new Node(v);
        if(head==nullptr){
            head=tail=newNode;
            length++;
            return;
        } else{
            
            tail->next=newNode;
            tail=newNode;
            tail->next=nullptr;
            length++;
        }
    }
    void print(){
        Node *temp;
        temp=head;
        while (temp!=nullptr)
        {
            cout<<temp->val<<"->";
            temp=temp->next;
        }
        cout<<"nullptr\n";
    }
    
    Node* reverse(Node *hea,int k){
        Node *curr=hea;
        Node *prev=nullptr;
        Node *next=nullptr;
        int count=0;
        while (curr!=nullptr&&count<k) {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            count++;
        }
        if (next!=nullptr) {
            hea->next=reverse(next,k);
        }
        return prev;
    }
    void reverse(int k){
        head= reverse(head,k);
    }
};

int main (){
    LinkList ll;
    ll.pushBack(1);
    ll.pushBack(2);
    ll.pushBack(3);
    ll.pushBack(4);
    ll.pushBack(5);
    ll.pushBack(6);
    ll.pushBack(7);
    ll.pushBack(8);
    ll.print();
    ll.reverse(4);
    ll.print();
}    