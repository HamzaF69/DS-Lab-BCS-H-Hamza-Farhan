#include <iostream>
#include <string>
using namespace std;

class Box {
public:
    int* size;
    bool deep;  
    Box(int i,bool d=true) { 
        size=new int(i);
        deep=d;
    }
    Box(const Box& obj) {
        deep=obj.deep;
        if(deep){
            size=new int(*obj.size); 
        } else{
            size=obj.size; 
        }
    }
    ~Box(){
        delete size;
    }
};

int main() {
    cout<<"shallow"<<endl;
    Box b1(10,false); 
    Box b2=b1;         
    *b2.size=99;
    cout<<"b1 size: "<<*b1.size<<" b2 size:"<<*b2.size<<endl;

    cout<<"-Deep Copy"<<endl;
    Box d1(10,true);    
    Box d2=d1;
    *d2.size =99;
    cout<<"d1 size:"<<*d1.size<<",d2 size:"<<*d2.size<<endl;
}
