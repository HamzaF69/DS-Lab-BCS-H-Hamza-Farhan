#include<iostream>
#include<string>
using namespace std;
int sumtail(int n, int total){
    if (n==0){
        return total;
    }
    total =total+ n;
    return sumtail(n-1,total);
}

int sumNontail(int n){
    if (n==0)
    {
        return 0;
    }
    return n+sumNontail(n-1);
}

int main() {
    int n;
    cout<<"enter number: ";
    cin>>n;
    cout<<"tail sum: "<<sumtail(n,0)<<endl;
    cout<<"nontail sum: "<<sumNontail(n);
    return 0;
}