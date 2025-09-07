#include <iostream>
#include <string>
using namespace std;

class Node{
    public:
    int val;
    Node *next;
    Node *child;
    Node (int v){
        val=v;
        next=child=nullptr;
    }
};
Node* flatten(Node* head) {
    Node* temp=head;
    Node* tail=head; 

    while (temp!=nullptr) {
        Node* nextNode= temp->next;
        if (temp->child != nullptr) {
            Node* childHead = flatten(temp->child); 
            temp->child = nullptr;                  
            temp->next = childHead;               
            Node* childTail = childHead;
            while (childTail->next != nullptr) {
                childTail=childTail->next;
            }
            childTail->next=nextNode;
            tail=childTail;
        } else {
            tail=temp;
        }

        temp=nextNode;
    }
    return head;
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

int main (){
    Node *head1= new Node(1);
    head1->next= new Node(2);
    head1->next->next= new Node(3);

    Node *head2= new Node(4);
    head2->next= new Node(5);

    head1->next->child=head2;


    print(head1);
    print(head2);
    flatten(head1);
    print(head1);
}

