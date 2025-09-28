#include <iostream>
#include <string>
using namespace std;

bool isSafe(int** arr,int x,int y, int n) {
    if (x >=0&&x <n&&y>=0&&y<n&&arr[x][y]==1) {
        return true;
    }
    return false;
}
bool ratInMaze(int** arr,int x,int y,int n,int** solArr){
    if ((x==n-1)&&(y==n-1)) {
        solArr[x][y]=1;
        return true;
    }
    if (isSafe(arr, x, y, n)) {
        solArr[x][y] = 1;
        if (ratInMaze(arr,x+1,y,n,solArr)) {
            return true;
        }
        if (ratInMaze(arr,x,y+1,n,solArr)) {
            return true;
        }
        if (ratInMaze(arr,x-1,y,n, solArr)) {
            return true;
        }
        if (ratInMaze(arr,x,y-1,n,solArr)) {
            return true;
        }
        solArr[x][y] = 0;
        return false;
    }
    return false;
}

int main() {
    int n;
    cout<<"enter maze size: ";
    cin>>n;
    int** arr=new int*[n];
    for (int i = 0; i<n; i++) {
        arr[i]=new int[n];
    }
    cout<<"enter maze\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin>>arr[i][j];
        }
    }
    int** newarr=new int*[n];
    for (int i=0;i<n;i++) {
        newarr[i]=new int[n];
        for (int j=0;j<n; j++) {
            newarr[i][j] = 0;
        }
    }
    if (ratInMaze(arr,0,0, n, newarr)) {
        cout<<"path found:\n";
        for (int i=0;i<n;i++) {
            for (int j = 0; j<n;j++) {
                cout<<newarr[i][j]<<" ";
            }
            cout<<endl;
        }
    }else{
        cout<<"no path";
    }
    return 0;
}