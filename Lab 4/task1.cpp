#include<iostream>
#include<string>
using namespace std;
 
int linearsearch(int arr[],int n, int val){
    for (int i = 0; i < n; i++)
    {
        if(arr[i]==val){
            return i;
        }
    }
    return -1;
    
}
int main() {
    int n;
    cout<<"enter size of array: ";
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout<<"enter value for index "<<i+1<<": ";
        cin>>arr[i];
    }
    int val;
    cout<<"enter value to search: ";
    cin>>val;
    int pos =linearsearch(arr,n,val);
    if(pos<0){
        cout<<"not found\n";
    } else{
        cout<<"value found at postion "<<pos<<endl;
    }
    return 0;
}
