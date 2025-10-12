#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string url;
    Node* next;
    Node(string u):url(u){
        next=nullptr;
    }
};

class Stack {
    Node* head;
public:
    Stack() {
        head = nullptr;
    }

    void push(string site){
        Node* newNode=new Node(site);
        newNode->next=head;
        head=newNode;
        cout<<"visited: "<<site<<endl;
    }

    void pop() {
        if (head==nullptr) {
            cout<<"No previous page\n";
            return;
        }
        cout<<"going back from: "<<head->url<<endl;
        Node* temp=head;
        head=head->next;
        delete temp;
    }
    void peek(){
        if (head==nullptr) {
            cout<<"no current page\n";
            return;
        }
        cout<<"current page: " << head->url << endl;
    }

    void display(){
        if (head==nullptr) {
            cout<<"no history.\n";
            return;
        }
        cout<<"History:\n";
        Node* temp=head;
        while (temp!=nullptr){
            cout<<temp->url<<endl;
            temp=temp->next;
        }
    }
};

int main() {
    Stack browser;
    browser.push("google.com");
    browser.push("youtube.com");
    browser.push("github.com");
    browser.display();
    browser.peek();
    browser.pop();
    browser.peek();
    browser.display();
    return 0;
}