#include <iostream>
#include <string>
using namespace std;

class Stack {
    char arr[100];
    int top;
public:
    Stack() { top = -1; }

    void push(char val) {
        arr[++top] = val;
    }

    char topPeek() {
        return arr[top];
    }
    char pop() {
        return arr[top--];
    }


    bool isEmpty() {
        return top == -1;
    }
};

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

string infixToPostfix(string infix) {
    Stack s;
    string postfix="";
    for (int i = 0; i < infix.length(); i++) {
        char ch=infix[i];
        if (ch==' '){
            continue;
        }

        if (isDigit(ch)) {
            postfix += ch;
            postfix += " ";
        }
        else if (ch == '(') {
            s.push(ch);
        }
        else if (ch == ')') {
            while (!s.isEmpty() && s.topPeek() != '(') {
                postfix += s.pop();
                postfix += " ";
            }
            s.pop();
        }

        else {
            while (!s.isEmpty() && precedence(s.topPeek()) >= precedence(ch)) {
                postfix += s.pop();
                postfix += " ";
            }
            s.push(ch);
        }
    }
    while (!s.isEmpty()) {
        postfix+=s.pop();
        postfix+=" ";
    }
    return postfix;
}

class Int{
    int arr[100];
    int top;
public:
    Int(){ 
        top = -1; 
    }
    void push(int val) { arr[++top] = val;}

    int pop() { return arr[top--];}

    bool isEmpty(){ return top==-1; }
};

int evalPostfix(string postfix) {
    Int s;
    for (int i = 0; i < postfix.length(); i++) {
        char ch = postfix[i];
        if (ch == ' ') {
            continue;
        }

        if (isDigit(ch)) {
            s.push(ch - '0');
        } else {
            int val2 = s.pop();
            int val1 = s.pop();

            switch (ch){
                case '+':{
                    s.push(val1+val2);
                    break;
                }
                case '-':{
                    s.push(val1-val2);
                    break;
                }
                case '*':{
                    s.push(val1*val2);
                    break;
                }
                case '/':{
                    s.push(val1/val2);
                    break;
                }
            }

        }
    }
    return s.pop();
}

int main() {
    string inf = "(9+17)/ 4 + 5 -2";
    cout<<"infix: "<<inf;
    string postf=infixToPostfix(inf);
    cout<<"\npostfix: "<<postf;
    int result = evalPostfix(postf);
    cout<<"\nresult: "<<result;
    return 0;
}