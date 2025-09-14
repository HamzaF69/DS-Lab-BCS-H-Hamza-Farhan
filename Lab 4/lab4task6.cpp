#include<iostream>
#include<string>
using namespace std;
 
void combsort(int arr[], int n){
    float shk=1.3;
    int gap=n;
    bool swap=true;
    while (gap>1||swap)
    {
        gap= (gap/shk);
        if (gap<1)
        {
            gap=1;
        }
        swap=false;
        for (int i = 0; i+gap< n; ++i)
        {
            if (arr[i]>arr[i+gap])
            {
                int temp= arr[i];
                arr[i]=arr[gap+i];
                arr[gap+i]=temp;
                swap=true;
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
    combsort(arr,n);
    cout<<"sorted array:\n";
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<endl;
    }
    return 0;
}