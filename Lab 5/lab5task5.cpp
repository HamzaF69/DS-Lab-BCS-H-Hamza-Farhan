#include <iostream>
#include <string>
using namespace std;

bool findEmptyCell(int grid[9][9], int &row, int &col);
bool solveSudoku(int grid[9][9]);

bool isVal(int grid[9][9], int row, int col, int num) {
        for (int x=0;x<9;x++){
            if (grid[row][x]==num){
                return false;
                }
        }
        
        for (int x=0;x<9;x++){
            if(grid[x][col]==num)
            {
                return false;
            }
        }
        
        int strR=row-row%3;
        int strC=col-col%3;
        for (int i=0;i<3; i++){
            for (int j = 0; j < 3; j++){
                if (grid[i+strR][j+strC]==num)
                {
                    return false;
                }
            }
        }
            return true;
}

bool solveSudoku(int grid[9][9]) {
                int row, col;
                
        if (!findEmptyCell(grid, row, col))
        {
            return true;
        }
        
        for (int num=1;num<=9;num++) {
            if (isVal(grid,row,col,num)) {
                grid[row][col]=num;
                if (solveSudoku(grid)){
                    return true;
                }    
                grid[row][col] = 0;
            }
        }
        return false;
}
bool findEmptyCell(int grid[9][9],int &row,int &col) {
    for (row=0;row<9;row++) {
        for (col=0;col<9;col++) {
            if (grid[row][col]==0)
            return true;
        }
    }
    return false;
}

void print(int grid[9][9]) {
    for(int row=0;row<9;row++) {
        for(int col = 0; col<9;col++) {
            cout<<grid[row][col]<<" ";
        }
        cout<<"\n";
    }
}

int main() {
    int grid[9][9]={
    {0,0,0,2,6,0,7,0,1},
    {6,8,0,0,7,0,0,9,0},
    {1,9,0,0,0,4,5,0,0},
    {8,2,0,1,0,0,0,4,0},
    {0,0,4,6,0,2,9,0,0},
    {0,5,0,0,0,3,0,2,8},
    {0,0,9,3,0,0,0,7,4},
    {0,4,0,0,5,0,0,3,6},
    {7,0,3,0,1,8,0,0,0}};

    if (solveSudoku(grid)){
        cout<<"sudoku solved:\n";
        print(grid);
    } else{
        cout<<"no solution";
    }
    return 0;

}
