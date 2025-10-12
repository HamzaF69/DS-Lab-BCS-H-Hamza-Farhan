#include <iostream>
#include <string>
using namespace std;

class Process {
public:
    int id;
    int priority;

    Process() {
        id = 0;
        priority = 0;
    }

    Process(int i, int p) {
        id = i;
        priority = p;
    }

    void display() {
        cout << "process ID: " << id << " | priority: " << priority << endl;
    }
};

class Queue {
    Process arr[100];
    int front, rear;
public:
    Queue() {
        front = 0;
        rear = -1;
    }

    bool isEmpty() {
        return rear < front;
    }

    void enqueue(Process p) {
        arr[++rear] = p;
    }

    Process dequeue() {
        return arr[front++];
    }

    void displayQueue() {
        cout << " queue\n";
        for (int i = front; i <= rear; i++) {
            arr[i].display();
        }
    }
};

class Stack {
    Process arr[100];
    int top;
public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(Process p) {
        arr[++top] = p;
    }

    Process pop() {
        return arr[top--];
    }

    void display() {
        cout << " stack:\n";
        for (int i = top; i >= 0; i--) {
            arr[i].display();
        }
    }
};

int main() {
    Queue q;
    Stack s;
    int n;

    cout<<"enter number of processes: ";
    cin>>n;

    for (int i = 0; i < n; i++) {
        int id, pr;
        cout<< "enter Process ID: ";
        cin>>id;
        cout<< "enter Priority (higher = more important): ";
        cin>>pr;
        q.enqueue(Process(id, pr));
    }

    q.displayQueue();
    cout<<"transferring high-priority processes to stack...\n";
    while(!q.isEmpty()){
        Process p=q.dequeue();
        if (p.priority>5){
            s.push(p);
        }
        else{
            cout<<"process "<< p.id <<" will wait.\n";
        }
    }

    s.display();
    cout<<"executing from Stack\n";
    while (!s.isEmpty()) {
        Process current = s.pop();
        cout<<"executing process ID: "<<current.id<<" | priority: " << current.priority << endl;
    }
    cout << "all high priority tasks executed\n";
    return 0;
}