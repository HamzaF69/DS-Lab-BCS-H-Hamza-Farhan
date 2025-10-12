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
    if (op=='+'||op=='-') {
        return 1;
    }
    if (op=='*'||op=='/') {
        return 2;
    }
    return 0;
}

bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

string reverseInfix(string infix) {
    string rev="";
    for (int i=infix.length()-1;i>= 0;i--) {
        if (infix[i]=='('){
            rev+=')';
        }
        else if(infix[i] == ')') {
            rev+='(';
        }
        else {
            rev+=infix[i];
        }
    }
    return rev;
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

string infixToPrefix(string infix) {
    infix = reverseInfix(infix);
    string postfix = infixToPostfix(infix);
    string token = "", prefix = "";
    string tokens[100];
    int count = 0;

    for (int i = 0; i < postfix.length(); i++) {
        if (postfix[i] != ' ') token += postfix[i];
        else if (!token.empty()) {
            tokens[count++] = token;
            token = "";
        }
    }
    if (!token.empty()) tokens[count++] = token;

    for (int i = count - 1; i >= 0; i--) {
        prefix += tokens[i] + " ";
    }

    return prefix;
}


class Int{
    int arr[100];
    int top;
public:
    Int(){ 
        top=-1; 
    }
    void push(int val) {
        arr[++top] = val;
    }

    int pop(){
        return arr[top--];
    }

    bool isEmpty(){
        return top==-1; 
    }
};

int evalPrefix(string prefix) {
    Int st;
    string tokens[100];
    string token= "";
    int count=0;
    for (int i=0;i<prefix.length();i++) {
        if (prefix[i]!=' ')
            token+=prefix[i];
        else if(!token.empty()){
            tokens[count++]=token;
            token="";
        }
    }
    if (!token.empty()) {
        tokens[count++] = token;
    }
    for (int i = count - 1; i >= 0; i--) {
        string c = tokens[i];
        if (c[0] >= '0' && c[0] <= '9') {
            st.push(stoi(c));
        } else {
            int val1 = st.pop();
            int val2 = st.pop();
            int res = 0;
            switch (c[0]) {
                case '+': res = val1 + val2; break;
                case '-': res = val1 - val2; break;
                case '*': res = val1 * val2; break;
                case '/': res = val1 / val2; break;
            }
            st.push(res);
        }
    }

    return st.pop();
}

int main() {

    string inf="(9+1)/4+5-2";
    cout<<"infix: " << inf << endl;
    string pref=infixToPrefix(inf);
    cout << "prefix: " << pref << endl;
    int result =evalPrefix(pref);
    cout << "result: "<<result<< endl;

    return 0;
}