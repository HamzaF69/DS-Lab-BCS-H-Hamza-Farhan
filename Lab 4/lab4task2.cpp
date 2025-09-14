#include<iostream>
#include<string>
using namespace std;
 
void bubblesort(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        for(int j = 0 ; j < n-1 ; j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    
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
    bubblesort(arr,n);
    cout<<"sorted array:\n";
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<endl;
    }
    
}