#include<iostream>
#include<string>
using namespace std;
 


void resize(int *&arr, int n, int size){
    
    int *temp= new int [size];
    for (int i = 0; i < n; i++)
    {
        temp[i]=arr[i];
    }
    for (int i = n; i < size; i++)
    {
        cout<<"enter new expenses for month "<<i+1<<" : ";
        cin>>temp[i];
    }
    delete[] arr;
    arr = temp;
    
}
int main() {
    int n;
    cout<<"enter number of months: ";
    cin>>n;
    int *arr= new int[n];
    for (int i = 0; i < n; i++)
    {
        cout<<"enter expenses for month "<<i+1<<" : ";
        cin>>arr[i];
    }
    int newSize;
    cout<<"how many months do want to change to: ";
    cin>>newSize;
    resize(arr, n,newSize);
    
    int total=0,avg;
    for (int i = 0; i < newSize; i++)
    {
        total+=arr[i];
    }
    avg = total/newSize;
    cout<<"average: "<<avg<<endl;
    cout<<"total: "<<total<<endl;

    return 0;
}