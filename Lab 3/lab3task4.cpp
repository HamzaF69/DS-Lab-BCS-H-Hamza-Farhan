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
            tail->next=head;
            length++;
            return;
        } else{
            newNode->next=head;
            tail->next=newNode;
            tail=newNode;
            length++;
        }
    }

    int josephus(int n, int k){
        Node *temp=head;
        Node *prev=tail;
        int count=0;
        while(length>1)
        {
            for (int i = 0; i < k - 1; i++) {
                prev = temp;
                temp = temp->next;
            }
            prev->next=temp->next;
            if (temp==head){
                head=temp->next;
            } 
            if (temp==tail){
                tail=prev;
            } 
            delete temp;
            temp=prev->next;
            length--;
        }

        return head->val;
        
    }


    void print(){
        cout<<head->val<<" -> ";
        Node *temp=head->next;
        while (temp!=head)
        {
            cout<<temp->val<<" -> ";
            temp=temp->next;
        }
        cout<<head->val<<" (head again)\n";        
    }
};

int main (){
    LinkList ll;
    int n,k;
    cout<<"enter N people:";
    cin>>n;
    cout<<"enter k-th person:";
    cin>>k;
    for (int i = 0; i < n; i++)
    {
        ll.pushBack(i+1);
    }
    ll.print();
    int pos=ll.josephus(n,k);
    ll.print();
    cout<<"survivor postion is: "<<pos<<endl;
    
}    