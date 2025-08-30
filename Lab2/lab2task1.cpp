#include<iostream>
#include<string>
using namespace std;
 

void change(int pos, int val,int *arr){
    arr[pos]=val;
    cout<<"changed\n";
}
int main() {
    int n;
    cout<<"enter length:";
    cin>>n;
    int *arr;
    arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        arr[i]=0;
    }
    while (1)
    {
        int i;
        cout<<"enter 1 if you want to change the value:";
        cin>>i;
        if (i!=1)
        {
            break;
        }
        int p,v;
        cout<<"what postion do you want: ";
        cin>>p;
        cout<<"what val do you want to change to: ";
        cin>>v;
        change(p,v,arr);
        for (int i = 0; i < n; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
