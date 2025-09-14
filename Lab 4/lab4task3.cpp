#include<iostream>
#include<string>
using namespace std;
 
void selectionsort(int arr[], int n){
    for (int i = 0; i < n-1; i++)
    {
        int min=i;
        for (int j = i+1; j < n; j++)
        {
            if(arr[j]<arr[min]){
                int temp=arr[j];
                arr[j]=arr[min];
                arr[min]=temp;
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
    selectionsort(arr,n);
    cout<<"sorted array:\n";
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<endl;
    }
    return 0;
}