#include <iostream>
#include <string>
using namespace std;


int main(){
    int r,c;
    cout<<"rows: "; 
    cin>>r;
    cout<<"cols: "; 
    cin>>c;

    int **mat=new int*[r];
    for (int i = 0; i < r; i++)
    {
        mat[i]=new int[c];
    }
    
    cout<<"enter elements:\n";
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cin>>mat[i][j];
        }
    }

    cout<<"\nmatrix:\n";
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++) 
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"\ncompressed:\n";
    for (int i = 0; i < r; i++) 
    {
        for (int j = 0; j < c; j++) 
        {
            if (mat[i][j] != 0) {
                cout<<i<<" "<<j<<" "<<mat[i][j]<<endl;
            }
        }
    }
    for (int i = 0; i < r; i++) {
        delete[] mat[i];
    }
    delete[] mat;
    return 0;
}