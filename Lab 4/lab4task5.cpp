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

int interpolationsearch(int arr[], int n, int val){
    int low=0;
    int high =n-1;
    while (low<=high && val>=arr[low] && val<=arr[high]){
        if(low==high){
            if(val==arr[low]){
                return low;
            }
            return -1;
        }

        int pos= low+((val-arr[low])*(high-low)) / (arr[high]-arr[low]);
        if (arr[pos]==val)
        {
            return pos;
        }
        if (arr[pos]<val)
        {
            low=pos+1;
        } else{
            high=pos-1;
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
    int pos=interpolationsearch(arr,n,val);
    if(pos<0){
        cout<<"not found\n";
    } else{
        cout<<"value found at postion "<<pos<<endl;
    }

    return 0;
}