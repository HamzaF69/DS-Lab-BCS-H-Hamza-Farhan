#include<iostream>
#include<string>
using namespace std;
void change(int r, int c,int **arr){
    if (arr[r][c]==1)
    {
        cout<<"seat already taken. choose a different seat\n";
        return;
    }
    
    arr[r][c]=1;
    cout<<"changed\n";
}

void print(int r, int c,int **arr){
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main() {
    int r,c;
    cout<<"enter rows and colums: ";
    cin>>r>>c;
    int **arr= new int*[r];
    for(int i = 0; i < r; i++){
        arr[i]= new int[c];
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            arr[i][j]=0;
        }
    }
    while (1)
    {
        print(r,c,arr);
        int i;
        cout<<"enter 1 if you want to book a seat: ";
        cin>>i;
        if (i!=1)
        {
            break;
        }
        int row,col;
        cout<<"what row do you want: ";
        cin>>row;
        cout<<"what column do you want: ";
        cin>>col;
        change(row-1,col-1,arr);
    }
    return 0;
}