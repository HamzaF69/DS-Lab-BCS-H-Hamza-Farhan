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

class DoublyNode{
    public:
    int val;
    DoublyNode *next;
    DoublyNode *prev;
    DoublyNode (int v){
        val=v;
        next=prev=nullptr;
    }
};

DoublyNode *convertToDoubly(Node *head){
    int len=0;
    
    DoublyNode* newhead = new DoublyNode(head->val);
    DoublyNode* doubcur =newhead;
    Node* singcur =head->next;

    while (singcur!=nullptr)
    {
        DoublyNode* newNode= new DoublyNode(singcur->val);
        doubcur->next=newNode;
        newNode->prev=doubcur;
        doubcur=newNode;
        singcur=singcur->next;
    }
    
    return newhead; 
}


void pushfront(Node *&head,int i){
        Node* newNode= new Node(i);
        if(head== nullptr){
            head=newNode;
        } else{
            newNode->next = head;
            head = newNode;
        }
    }
    
void convertTocircular(Node *head){
        Node *temp=head;
        while (temp->next!=nullptr)
        {
        temp=temp->next;
    }
    temp->next=head;
}
void print(Node *head){
        Node *temp;
        temp=head;
        while (temp!=nullptr)
        {
            cout<<temp->val<<"->";
            temp=temp->next;
        }
        cout<<"nullptr\n";
}

void printDoubly(DoublyNode *head){
        DoublyNode *temp;
        temp=head;
        while (temp!=nullptr)
        {
            cout<<temp->val<<"<->";
            temp=temp->next;
        }
        cout<<"nullptr\n";
}

void printCircular(Node* head){
    cout<<head->val<<" -> ";
        Node *temp=head->next;
        while (temp!=head)
        {
            cout<<temp->val<<" -> ";
            temp=temp->next;
        }
    cout<<head->val<<" (head again)\n";
}


int main (){
    Node *head1= new Node(1);
    pushfront(head1,2);
    pushfront(head1,3);
    pushfront(head1,4);
    print(head1);
    convertTocircular(head1);
    printCircular(head1);

    Node *head2= new Node(1);
    pushfront(head2,2);
    pushfront(head2,3);
    pushfront(head2,4);
    print(head2);

    DoublyNode* head3= convertToDoubly(head2);
    printDoubly(head3);

}