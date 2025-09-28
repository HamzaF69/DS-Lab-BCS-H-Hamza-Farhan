#include <iostream>
#include <string>
using namespace std;

void printBoard(int board[20][20], int n) {
    for (int i = 0;i <n;i++) {
        for (int j = 0; j <n;j++) {
            if (board[i][j]==1) {
                cout<<"q ";
            } else{
                cout<<". ";
            }
        }
        cout<<endl;
    }
    cout<<endl;
}

bool isSafe(int board[20][20],int row,int col,int n){
    for (int i=0;i<row;i++){
        if (board[i][col]) {
            return false;
        }
    }
    for (int i=row-1,j=col-1;i>=0&&j>=0;i--,j--){
        if (board[i][j]){
            return false;
        }
    }
    for (int i=row-1,j=col+1;i>=0&&j<n;i--,j++){
        if (board[i][j]){
            return false;
        }
    }
    return true;
}

void solveNQueens(int board[20][20],int row,int n){
    if(row==n){
        printBoard(board, n);
        return;
    }

    for (int col=0;col<n;col++) {
        if (isSafe(board,row,col,n)) {
            board[row][col]=1;
            solveNQueens(board,row+1,n);
            board[row][col]=0;
        }
    }
}

int main(){
    int n;
    cout<<"enter value of n:";
    cin>>n;
    int board[20][20]={0};
    cout<<"solution\n";
    solveNQueens(board,0,n);
    return 0;
}