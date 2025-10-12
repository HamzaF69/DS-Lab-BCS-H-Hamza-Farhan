#include <iostream>
#include <string>
using namespace std;

class CircularQ {
private:
    int arr[5];
    int front, rear;

public:
    CircularQ() {
        front=-1;
        rear=-1;
    }
    void enqueue(int val) {
        if (isFull()) {
            cout<<"queue overflow"<<endl;
            return;
        }
        if (front == -1){ 
            front = 0;
        }
        rear=(rear+1)%5;
        arr[rear]=val;
        cout<<val<<" enqueued"<<endl;
    }
    
    void dequeue(){
        if (isEmpty()){
            cout<<"queue underflow" << endl;
            return;
        }
        
        cout<<arr[front]<<" dequeued successfully!" << endl;
        
        if (front==rear){
            front=rear=-1;
        } else {
            front=(front+1)%5;
        }
    }
    
    void display() {
        if (isEmpty()) {
            cout << "queue is empty" << endl;
            return;
        }
        cout << "queue contents: ";
        int i = front;
        while(true){
            cout<<arr[i] << " ";
            if(i==rear){
                break;
            }
            i=(i+1)%5;
        }
        cout<<endl;
    }

    bool isFull(){
        return (front==0&&rear==4)||(front==rear+1);
    }
    bool isEmpty(){
        return (front==-1);
    }
};

int main() {
    CircularQ queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);
    queue.enqueue(6);
    queue.enqueue(7);
    queue.display();
    queue.dequeue();
    queue.dequeue();
    queue.display();
    return 0;
}