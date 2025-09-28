#include <iostream>
#include <string>
using namespace std;

void print(int n){
    if(n>0){
        cout<<n<<" ";
        print(n-1);
    }
}
void functionB(int b);
void functionA(int a){
    if (a <= 0) return;
    if(a%2==0){
        cout<<a<<" even"<<endl;
    } else {
        cout<<a<<" odd"<<endl;
        functionB(a-1);
    }
}
void functionB(int b){
    if (b <= 0) return;
    if(b%2!=0){
        cout<<b<<" odd"<<endl;
    } else {
        cout<<b<<" even"<<endl;
        functionA(b-1);
    }
}

int main(){
    int n=4;
    print(n);
    cout<<"\n";
    functionA(9);
}