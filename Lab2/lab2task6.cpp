#include <iostream>
#include <string>
using namespace std;

class SafePointer{
    int* ptr;
    public:
    SafePointer(int size=1){
        ptr=new int[size];
    }
    void setValue(int ind,int val) {
        ptr[ind] = val;
    }
    int getValue(int ind){
        return ptr[ind];
    }
    void release(){
        if (ptr) {
            delete[] ptr;
            ptr=nullptr;
        }
    }
    ~SafePointer() {
        release();
    }
};

int main() {
    int n = 5;
    SafePointer marks(n);
    for (int i=0;i<n;i++) {
        int m;
        cout<<"enter marks for student "<<i+1<<": ";
        cin>>m;
        marks.setValue(i,m);
    }

    cout << "stored Marks:\n";
    for (int i = 0; i < n; i++) {
        cout<<"student "<<i+1<<": "<<marks.getValue(i)<<endl;
    }
    return 0;
}
