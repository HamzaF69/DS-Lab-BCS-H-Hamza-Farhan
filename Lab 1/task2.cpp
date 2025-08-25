#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Exam {
    private:
    char* name;
    char* date;
    int* marks;
    public:
    Exam(const char* n,const char* d,int m){
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        date = new char[strlen(d) + 1];
        strcpy(date, d);
        marks = new int(m);
    }
    void setName(const char* n){
        delete[] name;
        name =new char[strlen(n)+1];
        strcpy(name,n);
    }
    void setDate(const char* d) {
        delete[] date;
        date = new char[strlen(d) + 1];
        strcpy(date, d);
    }
    void setMarks(int m){
        *marks = m;
    }
    void show()const{
        cout<< "name: "<<name<<endl;
        cout <<"date: " <<date<<endl;
        cout<<"marks: "<< *marks<<endl;
    }
    ~Exam(){
        cout<<"destructor called \n";
        delete[] name;
        delete[] date;
        delete marks;
    }
};

int main() {
    Exam ex1("hamza","17/april/2022",95);
    cout<<"original:"<< endl;
    ex1.show();
    Exam ex2=ex1;
    cout<<"copied"<<endl;
    ex2.show();
}
