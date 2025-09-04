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
    void mergeLL(LinkList &obj){
        tail->next=obj.head;
        tail=obj.tail;
    }
    void sort(){
        bool swap=true;
        Node* last=nullptr;
        do
        {
            swap=false;
            Node *cur=head;
            Node *prev=nullptr;
            while (cur->next!=last)
            {
                Node* nextNode=cur->next;
                if (cur->val>nextNode->val)
                {
                    cur->next=nextNode->next;
                    nextNode->next=cur;
                    prev->next=nextNode;
                    prev=nextNode;
                    swap=true;
                }else {
                    prev=cur;
                    cur=cur->next;
                }
            }
            last=cur;
        } while (swap==true);
    

            tail = head;
            while (tail && tail->next) {
                tail = tail->next;
            }
    }
};

int main (){
    LinkList ll1, ll2;
    ll1.pushBack(1);
    ll1.pushBack(3);
    ll1.pushBack(5);
    ll2.pushBack(2);
    ll2.pushBack(4);
    ll2.pushBack(6);
    LinkList ll3=ll1;
    ll3.mergeLL(ll2);
    ll3.print();
    ll3.sort();
    ll3.print();
}