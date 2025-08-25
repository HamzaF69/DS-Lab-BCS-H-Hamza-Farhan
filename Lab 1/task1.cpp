#include <iostream>
#include <string>
using namespace std;

class BankAccount{
    int balance;
    public:
    BankAccount():balance(0){
        cout<<"balance: "<<balance<<endl;
    }
    BankAccount(int b):balance(b){
        cout<<"balance: "<<balance<<endl;
    }
    BankAccount(BankAccount &obj){
        balance = (obj.balance);
        balance= balance-200;
    }
    void bal(){cout<<"current balance: "<<balance<<endl;}
};


int main (){
    BankAccount account1;
    BankAccount account2(1000) ;
    BankAccount account3 = account2;
    account1.bal();
    account2.bal();
    account3.bal();
    account2.bal();

}
