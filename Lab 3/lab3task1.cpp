#include <iostream>
#include <string>
using namespace std;

class Node{
    public:
    char val;
    Node *next;
    Node (char v){
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

    void pushBack(char v){
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
            cout<<temp->val;
            temp=temp->next;
        }
        cout<<"\n";
    }
    int isPal(){
        string s1, s2;
        if(length%2==0){
            for (int i = 0; i < length/2; i++)
            {
                s1+=head->val;
                head=head->next;
            }
            for (int i = 0; i < length/2; i++)
            {
                s2+=head->val;
                head=head->next;
            }
        } else{
            for (int i = 0; i < length/2; i++)
            {
                s1+=head->val;
                head=head->next;
            }
                head=head->next;
            for (int i = 0; i < length/2; i++)
            {
                s2+=head->val;
                head=head->next;
            }   
        }
        
        for (int i = 0; i < length/2; i++)
        {
            if(s1[i]!=s2[(length/2)-i-1]){
                
                return 0;
            }
        }
        return 1;
    }
};

int main (){
    LinkList ll;
    ll.pushBack('r');
    ll.pushBack('a');
    ll.pushBack('c');
    ll.pushBack('e');
    ll.pushBack('c');
    ll.pushBack('a');
    ll.pushBack('r');
    ll.print();
    if (ll.isPal()==1)
    {
        cout<<"it is a palindrome\n";
    }else
    {
        cout<<"it is not a palindrome\n";
    }
    
    
}
