#include <iostream>
#include <string>
using namespace std;

class Stack {
    int arr[100]; 
    int top; 
public:
    Stack(){
        top = -1;
    }

    void push(int val){
        if (top >100 ){
            cout<<"Stack Overflow! Cannot push "<<val<<endl;
        } else {
            top++;
            arr[top]=val;
            cout<<val<<" pushed into stack\n";
        }
    }

    void pop(){
            cout<<arr[top]<<" popped from stack.\n";
            top--;
    }

    void peek() {
            cout<<"top element: " <<arr[top]<<endl;
    }
    void display() {
        cout << "stack contents: ";
        for (int i=top;i>=0;i--) {
            cout << arr[i] << " ";
        }
        cout<<"\n";
    }
};



int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.display();
    s.pop();
    s.peek();
    return 0;
}
