#include<iostream>
#include<string>
using namespace std;

class Info{
    public:
    int swaps=0;
    int comp=0;
};
void shellsort(int arr[], int n,Info &i){
    for (int gap= n/2;gap>0; gap=gap/2)
    {
        for (int j=gap; j < n; j++)
        {
            int temp= arr[j];
            int res=j;
            while (res>=gap){
                i.comp++;
                if (arr[res-gap]>temp) {
                    arr[res]=arr[res-gap];
                    res-=gap;
                    i.swaps++;
                }else{
				    break;
			    }
            }
            arr[res]=temp;
        }
    } 
}

void bubblesort(int arr[], int n,Info &b){
    for (int i = 0; i < n; i++)
    {
        for(int j = 0 ; j < n-1 ; j++){
            b.comp++;
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                b.swaps++;
            }
        }
    }
}

void insertionsort(int arr[], int n,Info &in){
    for (int i = 0; i < n; i++)
    {
        int key =arr[i];
        int j=i-1;
        while (j>=0 )
        {
            in.comp++;
            if (arr[j]>key){
                arr[j+1]=arr[j];
                in.swaps++;
                j--;
            }else{
				break;
			}
        }
        arr[j+1]=key;
    }
}

int main() {
    int n;
    cout<<"enter size of array: ";
    cin>>n;
    int arr1[n],arr2[n],arr3[n];
    for (int i = 0; i < n; i++)
    {
        cout<<"enter value for index "<<i+1<<": ";
        cin >> arr1[i];
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
    }
    cout<<"unsorted array:\n";
    for (int i = 0; i < n; i++)
    {
        cout<<arr1[i]<<endl;
    }
    Info shell,bubble,insertion;
    shellsort(arr1,n,shell);
    bubblesort(arr2,n,bubble);
    insertionsort(arr3,n,insertion);
    cout<<"shell sorted array:\n";
    for (int i = 0; i < n; i++)
    {
        cout<<arr1[i]<<" ";
    }
    cout<<"comparisions: "<<shell.comp<<" swaps: "<<shell.swaps<<endl;
    cout<<"bubble sorted array:\n";
    for (int i = 0; i < n; i++)
    {
        cout<<arr2[i]<<" ";
    }
    cout<<"comparisions: "<<bubble.comp<<" swaps: "<<bubble.swaps<<endl;
    cout<<"insertion sorted array:\n";
    for (int i = 0; i < n; i++)
    {
        cout<<arr3[i]<<" ";
    }
    cout<<"comparisions: "<<insertion.comp<<" swaps: "<<insertion.swaps<<endl;
    return 0;
}
