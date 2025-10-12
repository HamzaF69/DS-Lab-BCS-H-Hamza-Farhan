#include <iostream>
#include <string>
using namespace std;

class Queue {
    int arr[100]; 
    int front, rear; 
public:
    Queue(){
        front=-1, rear=-1;
    }

    void enqueue(int val){
        if (isFull()) {
            cout<<"queue is full"<<endl;
            return;
        }
        if(front ==-1){
            front =0;
        }
        rear++;
        arr[rear]=val;
    }

    void dequeue(){
        if (isEmpty()){
            cout<<"queue is empty\n";
            return;
        }
        cout<<arr[front]<<" dequeued.\n";
        front++;
        if (front > rear){
            front = rear=-1;
        }
    }
    void display() {
        if(isEmpty()){
            cout<<"queue is empty\n";
            return;
        }
        cout<<"queue contents: ";
        for(int i = front; i <= rear; i++) {
            cout<<arr[i]<< " ";
        }
        cout<<endl;
    }
    bool isEmpty() {
        return (front==-1);
    }

    bool isFull() {
        return (rear ==99);
    }
};


int main(){
    Queue queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);
    queue.display();
    queue.dequeue();
    queue.dequeue();
    queue.display();
    return 0;
}