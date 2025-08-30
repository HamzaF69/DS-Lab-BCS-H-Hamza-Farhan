#include<iostream>
#include<string>
#include <cstdlib>
using namespace std;


void print(int **m, int r, int c){
    for (int i = 0; i < r; i++)
    {
       for (int j = 0; j<c; j++)
       {
        cout<<m[i][j]<<" ";
       }
       cout<<endl;
    }
}

int** add(int **m1,int **m2, int r, int c){
    int **temp =new int*[r];
    for (int i = 0; i < r; i++)
    {
        temp[i] = new int[c];
    }

    for (int i = 0; i < r; i++)
    {
       for (int j = 0; j<c; j++)
       {
        temp[i][j]=m1[i][j]+m2[i][j];
       }
    }
    return temp;
}

int** subtract(int **m1,int **m2, int r, int c){
    int **temp =new int*[r];
    for (int i = 0; i < r; i++)
    {
        temp[i] = new int[c];
    }

    for (int i = 0; i < r; i++)
    {
       for (int j = 0; j<c; j++)
       {
        temp[i][j]=m1[i][j]-m2[i][j];
       }
    }
    return temp;
}
int main() {
    int r=3;
    int c=3;
    int **m1 =new int*[r];
    int **m2 =new int*[r];
    for (int i = 0; i < r; i++)
    {
        m1[i] = new int[c];
        m2[i] = new int[c];
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            m1[i][j]= (rand() % 10);
            m2[i][j]= (rand() % 10);
        }
    }
    cout<<"matrix 1:\n";
    print(m1,r,c);
    cout<<"matrix 2:\n";
    print(m2,r,c);
    cout<<"after adding:\n";
    
    print(add(m1,m2,r,c),r,c);
    cout<<"after subtracting:\n";
    print(subtract(m1,m2,r,c),r,c);
    
    return 0;
}