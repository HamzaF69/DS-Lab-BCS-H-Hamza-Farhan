#include<iostream>
#include<string>
using namespace std;
 
void insertionsort(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        int key =arr[i];
        int j=i-1;
        while (j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
        
    }
}

int binarysearch(int arr[], int n, int val){
    int s=0,e=n;
    while (s<=e)
    {
       int mid=(s+e)/2;
       if (arr[mid]==val){
        return mid;
       } else if(arr[mid]>val){
        e=mid-1;
       }else if(arr[mid]<val){
        s=mid+1;
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
    cout<<"unsorted array:\n";
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<endl;
    }
    insertionsort(arr,n);
    cout<<"sorted array:\n";
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<endl;
    }
    int val;
    cout<<"enter value to search: ";
    cin>>val;
    int pos=binarysearch(arr,n,val);
    if(pos<0){
        cout<<"not found\n";
    } else{
        cout<<"value found at postion "<<pos<<endl;
    }

    return 0;
}